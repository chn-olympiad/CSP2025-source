#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+5,mod=998244353;
ll a[N];
ll ans=0;
inline ll C(ll x,ll y){
    ll c=1,cs=1;
    for(int i=0;i<y;i++){
        c*=(x-i);
        cs*=(y-i);
    }
    return c/cs;
}
inline ll check(int maxn,int st,int num,ll all){
    ll nowAns=0;
    if(num==0)return (ll)((a[maxn]*2)<all);
    for(int i=st-1;i>=num-1;i--)nowAns=(nowAns+check(maxn,i,num-1,all+a[i]))%mod;
    return nowAns;
}
int main(){
    //Open IO Files
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n;
    scanf("%lld",&n);
    for(ll i=0;i<n;i++)scanf("%lld",&a[i]);
    sort(a,a+n);
    if(a[n-1]==1){
        for(int i=3;i<=n;i++)ans=(ans+C(n,i))%mod;
    }else{
        for(int i=n-1;i>1;i--){
            for(int j=2;j<=i;j++)ans=(ans+check(i,i,j,a[i]))%mod;
        }
    }
    printf("%lld\n",ans);
    //Close IO Files
    fclose(stdin);
    fclose(stdout);
    return 0;
}