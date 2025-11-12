#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
string t1[N],t2[N];
using ull = long long;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
    {
        cin >> t1[i] >> t2[i];
    }
    while(q--)
    {
        string s1,s2;
        cin >> s1 >> s2;
        if(s1.size() != s2.size())
        {
            cout << 0 << "\n";
            continue;
        }
        else
        {
            ull ans = 0;
            for(int i = 1;i <= n;i++)
            {
                int l = 0;
                for(int j = 1;j <= s1.size();j++)
                {
                    if(s1[j] == t1[i][l] and s2[j] == t2[i][l])
                    {
                        l++;
                    }
                }
                if(l == t1[i].size())
                {
                    ans++;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
