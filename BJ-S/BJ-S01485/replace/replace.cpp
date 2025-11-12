#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    unordered_map<int, unordered_map<string, vector<string>>> replacements;
    for (int i = 0; i < n; ++i)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int len = s1.length();
        replacements[len][s1].push_back(s2);
    }
    while (q--)
        {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length())
        {
            cout << 0 << endl;
            continue;
        }
        int len = t1.length();
        int count = 0;
        for (auto& [L, rule] : replacements) {
            if (L > len) continue;
            for (int i = 0; i <= len - L; ++i)
            {
                string sub = t1.substr(i, L);
                if (rule.find(sub) == rule.end()) continue;
                string prefix = t1.substr(0, i);
                string suffix = t1.substr(i + L);
                for (string& rep : rule[sub])
                {
                    if (prefix + rep + suffix == t2)
                    {
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
