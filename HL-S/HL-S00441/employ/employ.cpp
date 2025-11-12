#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
const int p=998244353;
namespace hcx{
    int c[550];
    bool vis[550];
    int n,m;
    string s;
    int ans=0;
    int de=0;
    void dfs(int x){
        if(n-de<m)return;
        if(x==n)ans++;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                bool f=0;
                if(c[i]<=de||s[x]=='0'){
                    de++;
                    f=1;
                }
                vis[i]=1;
                dfs(x+1);
                vis[i]=0;
                de-=f;
            }
        }
    }
    void main(){
        
        cin>>n>>m;
        cin>>s;
        bool chk=1;
        for(int i=0;i<s.size();i++){
            chk&=s[i]=='1';
        }
        for(int i=1;i<=n;i++){
            cin>>c[i];
        }
        // if(chk){
        //     ll ans=1;
        //     for(int i=1;i<=n;i++){
        //         ans=ans*i%p;
        //     }
        //     cout<<ans<<"\n";
        //     return;
        // }
        s=" "+s;
        dfs(1);
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    hcx::main();
    return 0;
}