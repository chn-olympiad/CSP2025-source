#include <bits/stdc++.h>
using namespace std;

const int NR = 2e5 +10;
string s1[NR], s2[NR];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >>n >>q;
    for(int i = 1; i<= n; i++)
    {
        cin >> s1[i] >> s2[i];
    }
    while(q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        int ans = 0;
        for(int i = 1; i<= n; i++)
        {
            //cout << i << "\n";
            //cout << t1.size() - s1[i].size() << "\n";
            for(int j = 0; j <= (int)t1.size() - (int)s1[i].size(); j++)
            {
                //cout << t1.substr(j, s1[i].size()) << "\n";
                if(t1.substr(j, s1[i].size()) == s1[i])
                {
                    //cout << t1.substr(0, j - 0 + 1) + s2[i] + t1.substr(j + s1[i].size() - 1) << "\n";
                    if(t1.substr(0, j - 0) + s2[i] + (j + s1[i].size() >= t1.size() ? "" : t1.substr(j + s1[i].size())) == t2)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
