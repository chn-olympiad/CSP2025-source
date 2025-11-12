#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans;
map< string,vector<string> > mp;
signed main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        string a,b; cin>>a>>b;
        mp[a].push_back(b);
    }
    while(q--) {
        ans=0;
        string s,ss;
        cin>>s>>ss;
        int l=s.size();
        string x="";
        for(int i=0;i<l;i++) {
            string s2="";
            for(int j=i;j<l;j++) {
                s2+=s[j];
                if(mp[s2].size()!=0) {
                    for(int k=0;k<mp[s2].size();k++)
                        if(x+mp[s2][k]+s.substr(j+1)==ss)
                            ans++;
                }
            }
            x+=s[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}