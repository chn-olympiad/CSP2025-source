#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,q;
map<string,map<string,int>> mp;
signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i = 1;i<=n;i++) {
        string s,t;cin>>s>>t;
        if(s==t)    {mp[s][t]++;continue;}
        mp[s][t]++;
    }
    while(q--) {
        string s,t;cin>>s>>t;
        int m = s.size();s = ' '+s,t = ' '+t;
        int l = 1,r = m,ans = 0;
        while(s[l]==t[l])   l++;
        while(s[r]==t[r])   r--;
        for(int i = 1;i<=l;i++) {
            string tmp1 = "",tmp2 = "";
            for(int j = i;j<r;j++)
                tmp1 += s[j],tmp2 += t[j];
            for(int j = r;j<=m;j++) {
                tmp1 += s[j],tmp2 += t[j];
                ans += mp[tmp1][tmp2];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}