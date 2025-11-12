#include <bits/stdc++.h>
using namespace std;
long long n,q,len,ans;
string s1,s2;
unordered_map<string,string> mp;
void dfs(int idx,string s)
{
    if (s == s2)
    {
        ans++;
        return;
    }
    for (int i = idx+1; i <= len; i++)
    {
        string tmp=s1.substr(idx+1,i-idx);
        dfs(i,s+tmp);
        if (mp.count(tmp))
            dfs(i,s+mp[tmp]);
    }
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int i;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        cin >> s1 >> s2;
        mp[s1] = s2;
    }
    while (q--)
    {
        cin >> s1 >> s2;
        s1='#'+s1, s2='#'+s2;
        len = s1.length();
        if (len != s2.length())
        {
            cout << 0 << "\n";
            continue;
        }
        ans = 0;
        dfs(0,"");
        cout << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}