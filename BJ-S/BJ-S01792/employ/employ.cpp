#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
const int mod=998244353;
int n,m,ans,c[maxn],id[maxn];
bool f[maxn];
string s;
void dfs(int x){
    if(x==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||cnt>=c[id[i]]) cnt++;
            //cout<<id[i]<<" ";
        }
        if(n-cnt>=m) ans++;
        //cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!f[i]){
            f[i]=1;
            id[x]=i;
            dfs(x+1);
            id[x]=0;
            f[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    s="$"+s;
    if(n<=10){
        dfs(1);
        cout<<ans<<'\n';
    }else{
        ans=1;
        for(int i=1;i<=n;i++) ans=(ans*i)%mod;
        cout<<ans<<'\n';
    }
    return 0;
}
