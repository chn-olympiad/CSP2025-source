#include <bits/stdc++.h>
using namespace std;

map<pair<string, string>, int> mp;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string s1, s2, ss1 = "", ss2 = "";
        cin >> s1 >> s2;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                ss1 += s1[i];
                ss2 += s2[i];
            }
        }
        pair<string, string> p;
        p.first = ss1;
        p.second = ss2;
        mp[p]++;
    }
    while (q--)
    {
                string s1, s2, ss1 = "", ss2 = "";
        cin >> s1 >> s2;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                ss1 += s1[i];
                ss2 += s2[i];
            }
        }
        pair<string, string> p;
        p.first = ss1;
        p.second = ss2;
        cout << mp[p] << endl;
    }
    return 0;
}
