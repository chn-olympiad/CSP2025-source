#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+10;
int n,q;
string s[N],t[N],ss,tt;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    while(q--){
        cin>>ss>>tt;
        int ans=0;
        for(int i=1;i<=n;i++){
            int pd=0;
            for(int j=0;j<ss.size();j++){
                int ok=1;
                for(int k=0;k<ss.size();k++){
                    if(j<=k&&k<j+s[i].size())continue;
                    if(ss[k]!=tt[k]){
                        ok=0;
                        break;
                    }
                }
                for(int k=j;k<j+s[i].size();k++){
                    if(ss[k]!=s[i][k-j]||tt[k]!=t[i][k-j]){
                        ok=0;
                        break;
                    }
                }
                if(ok){
                    pd=1;
                    break;
                }
            }
            ans+=pd;
        }
        cout<<ans<<endl;
    }
    return 0;
}
