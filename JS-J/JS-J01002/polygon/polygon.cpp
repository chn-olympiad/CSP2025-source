#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,x,ans,a[5005],s[5005],c[5005],dp[105][105];
ll power(ll a,ll n){
    ll ret=1;
    for(ll i=1;i<=n;i++){
        (ret*=a)%=mod;
    }
    return ret;
}

/* another work*/
void dfs(ll dep,ll sum,ll maxn,ll cnt){
    if(dep>n){
        if(sum>2*maxn&&cnt>=3)ans++;
        return;
    }
    dfs(dep+1,sum+a[dep],max(a[dep],maxn),cnt+1);
    dfs(dep+1,sum,maxn,cnt);
}
void another_work(){
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    dfs(1,0,0,0);
    printf("%lld",ans);
}
void another_work2(){
    printf("%lld",(power(2,n)-1-n-n*(n-1)/2+2*mod)%mod);
}

/*main work*/
void init(){
    c[0]=1;
    for(ll i=1;i<=n;i++){
        c[i]=c[i-1]*i%mod;
    }
}
ll fracmod(ll x,ll y){//x/y mod 998244353
    for(ll i=0;i<y;i++){
        if((x+mod*i)/y*y==x+mod*i){
            return (x+mod*i)/y%mod;
        }
    }
}
ll C(ll m,ll n){
    return fracmod(fracmod(c[m],c[n]),c[m-n]);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    if(n<=20){
        another_work();
        return 0;
    }
    init();
    for(ll i=1;i<=n;i++){
        scanf("%lld",&x);
        a[x]++;
    }
    if(a[1]==n){
        another_work2();
        return 0;
    }
    for(ll i=100;i>=1;i--){
        s[i]=s[i+1]+a[i];
    }
    for(ll i=1;i<=100;i++){
        dp[i][1]=a[i];
    }
    for(ll j=2;j<=100;j++){
        for(ll i=j;i<=100;i++){
            for(ll k=1;k<j;k++){
                for(ll l=1;l<i;l++){
                    (dp[i][j]+=dp[l][k]*dp[i-l][j-k]%mod)%=mod;
                }
            }
        }
    }
    for(ll i=1;i<=100;i++){
        for(ll j=1;j<=100;j++){
            cout<<dp[i][j]<<" ";
            (ans+=s[i]*dp[i][j])%=mod;
        }
        cout<<endl;
    }
    printf("%lld",(power(2,n)-1-n-n*(n-1)/2+2*mod-ans)%mod);
    return 0;
}
