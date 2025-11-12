#include <bits/stdc++.h>
using namespace std;
#define int long long
namespace fisher{
const int N=5e2+5,mod=998244353;
// #define lowbit(x) ((x)&(-(x)))
int n,m,ans,c[N],p[N];
// int f[20][N*(N+50)];
bool v[N];
char s[N];
void dfs(int w,int num){
    if(w>n&&n-num>=m){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++) if(!v[i]){
        v[i]=1;
        p[w]=i;
        if(s[w]=='0'||num>=c[i]) dfs(w+1,num+1);
        else dfs(w+1,num);
        v[i]=0;
    }
}
// int gnum(int x){
//     int res=0;
//     for(;x;x-=lowbit(x)) res++;
//     return res;
// }
signed ckt(){
    cin>>n>>m>>(s+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    // f[0][0]=1;
    // for(int i=0;i<=n;i++) for(int j=1;j<(1<<n);j++){
    //     for(int k=1;k<=n;k++) if((1<<(k-1))&j){
    //         if(i){
    //             if(i&&(s[gnum(j)]=='0'||i>=c[k])) (f[i][j]+=f[i-1][j^(1<<(k-1))])%=mod;
    //             else (f[i][j]+=f[i][j^(1<<(k-1))])%=mod;
    //         }else if(s[gnum(j)]=='1') (f[i][j]+=f[i][j^(1<<(k-1))])%=mod;
    //     }
    // }
    // for(int i=0;i<=n-m;i++){
    //     (ans+=f[i][(1<<n)-1])%=mod;
    //     cout<<f[i][(1<<n)-1]<<" \n"[i==n];
    // }
    dfs(1,0);
    cout<<ans<<'\n';
    return 0;
}}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    return fisher::ckt();
}