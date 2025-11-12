#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#define ll long long
using namespace std;
map<string,string> m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll n,q;
    cin >> n >> q;
    for (ll i = 1;i <= n;i++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        m[s1] = s2;
    }
    while (q--)
    {
        string t1,t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length())
        {
            cout << "0\n";
            continue;
        }
        ll cur1,cur2,ans = 0;
        for (ll i = 0;i < n;i++)
        {
            if (t1[i] != t2[i])
            {
                cur1 = i-1;
                break;
            }
        }
        for (ll i = n;i > 0;i--)
        {
            if (t1[i] != t2[i])
            {
                cur2 = i+1;
                break;
            }
        }
        for (ll i = 0;i <= cur1;i++)
        {
            for (ll j = n;j <= n;j++)
            {
                string s = "",t = "";
                for (ll k = i+1;k < j;k++) s += t1[k],t += t2[k];
                if (m[s] == t)
                {
                    cout << s << " ";
                    ans++;
                }
            }
        }
        if (m[t1] == t2)
        {
            ans++;
            cout << t1 << " ";
        }
        cout << ans << "\n";
    }
    return 0;
}
