#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500,mod=998244353;
int n,m,c[N],sum=1,fl,jl[N],vis[N],ans;
string s=" ",ss;
void dfs(int p){
    if(p>n){
        int jsq=0,num=0;
        for(int i=1;i<=n;i++){
            if(jsq>=c[jl[i]]||s[i]=='0'){
                jsq++;
                continue;
            }
            num++;
        }
        if(num>=m)ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            jl[p]=i;
            vis[i]=1;
            dfs(p+1);
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>ss;
    s+=ss;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(s[i]=='0'||c[i]==0)fl=1;
        sum=sum*i%mod;
    }
    if(m==n){
        if(fl)cout<<0;
        else cout<<sum;
        return 0;
    }
    dfs(1);
    cout<<ans;
    return 0;
}
