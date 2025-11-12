#include<bits/stdc++.h>
#define long long
using namespace std;
int n,q;
string s[100010],t[100010],s1,s2;
int sch(string x)
{
    int lx = x.length();
    if(lx > s1.length()) return 0;
    if(lx == s1.length()) return x == s1;
    for(int i = 0;i < s1.length() - lx;i++)
    {
        if(s1.substr(i,lx) == x) return i + 1;
    }
    return 0;
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> s[i] >> t[i];
    while(q--)
    {
        cin >> s1 >> s2;
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            int a = sch(s[i]);
            if(!a) continue;
            string tt = s1.substr(0,a - 1) + t[i] + s1.substr(a + s[i].length() - 1);
            if(tt == s2) ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}
