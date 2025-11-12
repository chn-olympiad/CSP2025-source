#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
#define int long long
#define pb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
int a[N],n,ans,f[N];
void dfs(int dep,int cnt,int ma,int sum){
    if(dep==n){
        if(sum>ma*2&&cnt>2){
            ans++;
            ans%=mod;
        }
        return ;
    }
    dfs(dep+1,cnt,ma,sum);
    dfs(dep+1,cnt+1,max(ma,a[dep+1]),sum+a[dep+1]);
}
int po(int x,int y){
    int res=1,fx=x,fy=y;
    while(fy){
        if(fy&1) res=res*fx,res%=mod;
        fx=fx*fx%mod;
        fy>>=1;
    }
    return res;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=25){
        dfs(0,0,0,0);
        cout<<ans<<'\n';
    }else{
        f[0]=1;
        for(int i=1;i<=n;i++) f[i]=f[i-1]*i,f[i]%=mod;
        for(int i=3;i<=n;i++){
            ans+=(f[n]*po(f[n-i],mod-2)*po(f[i],mod-2));
            ans%=mod;
        }
        cout<<ans<<'\n';
    }
    return 0;
}