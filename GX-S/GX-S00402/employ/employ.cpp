#include<bits/stdc++.h>
#define N 600
#define int long long
using namespace std;
int sum[N],abi[N],test[N];
int j[N];
int n,m,num0,flag0,ans;
const int MOD=998244353;
bool used[N];
int App(int x){
    int res=1;
    for(int i=x;i>=1;i--)
    {
        res*=i;
        res%=MOD;
    }
    return res%MOD;
}
void dfs(int x,int p,int np){
    if(x==n+1&&p>=m) {ans=(ans+1)%MOD;return;}
    if(np>n-m) return;
    if(p==m) {ans+=j[n-(x-1)];ans%=MOD;return;}
    for(int i=1;i<=n;i++){
        if(used[i]) continue;
        used[i]=1;
        if(np>=abi[i]||test[x]==0){
            dfs(x+1,p,np+1);
        }else dfs(x+1,p+1,np);
        used[i]=0;
    }
}
void solve1(){
    dfs(1,0,0);//mem    passed    no_passed    前面的人成功数量
    cout<<ans%MOD;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    j[1]=1;
    for(int i=2;i<=n;i++) j[i]=i*j[i-1];
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        sum[i]=sum[i-1]+c-'0';
        test[i]=c-'0';
        //cout<<sum[i]<<' ';
    }
    for(int i=1;i<=n;i++) {cin>>abi[i];if(abi==0) num0++;}
    sort(abi+1,abi+1+n);
    if(n-num0<m) {cout<<0;return 0;}
    if(m==n&&(sum[n]!=n||num0>0)) {cout<<0;return 0;}
    if(sum[n]==n) {cout<<j[n];return 0;}
    if(n<=18) solve1();
    if(n>18) cout<<0;
    return 0;
}
