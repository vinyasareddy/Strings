class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size())
            return false;

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        // Frequency of s1
        for(int i = 0; i < s1.size(); i++) {
            m1[s1[i]]++;
        }

        // First window
        for(int i = 0; i < s1.size(); i++) {
            m2[s2[i]]++;
        }

        if(m1 == m2)
            return true;

        // Sliding window
        for(int i = s1.size(); i < s2.size(); i++) {

            // Add new character
            m2[s2[i]]++;

            // Remove old character
            m2[s2[i - s1.size()]]--;

            // Remove characters whose count became 0
            if(m2[s2[i - s1.size()]] == 0) {
                m2.erase(s2[i - s1.size()]);
            }

            if(m1 == m2)
                return true;
        }

        return false;
    }
};