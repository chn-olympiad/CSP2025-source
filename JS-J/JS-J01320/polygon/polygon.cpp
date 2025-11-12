#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10,M=5e3+10;
const ll mod=998244353;
ll n,a[N],sum[N],dp[N][M];
ll qp(ll b,ll k){
    ll sum=1;
    while(k){
        if(k&1) sum=sum*b%mod;
        b=b*b%mod;
        k>>=1;
    }
    return sum;
}
void solve1(){
    int cnt[N];
    ll res=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            cnt[j]=0;
            if(i&(1<<(j-1))) cnt[j]=1;
        }
        ll ans=0,maxn=0,tot=0;
        for(int j=1;j<=n;j++){
            if(cnt[j]==1){
                ans+=a[j];
                tot++;
                maxn=max(maxn,a[j]);
            }
        }
        if(tot>=3&&ans>maxn*2){
            res++;
        }
    }
    cout<<res%mod;
    return;
}
void solve2(){
    cout<<((qp(2,n)-1-n-n*(n-1)/2)%mod+mod)%mod;
    return;
}
void solve3(){
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<M;j++){
            if(j>=a[i])dp[i][j]=(dp[i-1][j-a[i]]+dp[i-1][j])%mod;
            else dp[i][j]=dp[i-1][j];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll cnt=0,tot=qp(2,i-1);
        for(int j=0;j<=a[i];j++){
            cnt=(cnt+dp[i-1][j])%mod;
        }
        ans=(ans+((tot-cnt)%mod+mod)%mod)%mod;
    }
    cout<<ans;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=20)solve1();
    else{
        int mark=1;
        for(int i=1;i<=n;i++){
            if(a[i]>1) mark=0;
        }
        if(mark){
            solve2();
        }
        else{
            solve3();
        }
    }
    return 0;
}
