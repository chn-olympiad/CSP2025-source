#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=510;
int n,m,a[N],ans,pre[N],inv[N];
bool vis[N];
string vs;
inline int qpow(int x,int y){
    int ans=1;
    while(y){
        if(y|1==1)ans=(ans*x)%mod;
        x=(x*x)%mod,y>>=1;
    }
    return ans;
}
inline int invo(int x){
    return qpow(x,mod-2);
}
inline void init(){
    pre[1]=1,inv[1]=1;
    for(int i=2;i<=500;i++)pre[i]=pre[i-1]*i%mod,inv[i]=invo(i);
}
inline void dfs(int x,int sum){
    if(x>n){
        ans+=(sum>=m);
        if(ans==mod)ans=0;
        return;
    }
    if(m-sum>n-x+1)return;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        if(vs[x-1]=='0'||a[i]<=x-sum-1)dfs(x+1,sum);
        else dfs(x+1,sum+1);
        vis[i]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    cin>>n>>m>>vs;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==n){
        if(vs.find('0'))cout<<0;
        else{
            bool bb=0;
            for(int i=1;i<=n;i++)if(a[i]==0){
                bb=1;
                break;
            }
            if(bb)cout<<0;
            else cout<<pre[n];
        }
        return 0;
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<pre[n];
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}