#include <bits/stdc++.h>
#define popcount __builtin_popcount
using namespace std;
using ll=long long;
using ull=unsigned long long;
namespace tools{
    ll powmod(ll x,ll a,ll p){
        ll res=1;
        for(;a;a>>=1,x=(x*x)%p){
            if(a&1){
                res=res*x%p;
            }
        }
        return res;
    }
    ll fac[5500],inv[5500];
    void C_init(int n,ll p){
        inv[0]=fac[0]=1;
        for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%p;
        inv[n]=powmod(fac[n],p-2,p);
        for(int i=n-1;i>=1;i--)inv[i]=inv[i+1]*(i+1)%p;
    }
    ll C(int x,int y,ll p){
        // if(y==0||y==x)return 1;
        // if(y>x)return 0;
        return fac[x]*inv[y]%p*inv[x-y]%p;
    }
};
namespace hcx{
    // using tools::powmod;
    int a[5500];
    const int p=998244353;
    // brute force 40
    // O(2^n n)
    void sol1(int n){
        int k=1<<n;
        int ans=0;
        for(int i=1;i<k;i++){
            //cout<<i<<" "<<popcount(i)<<"\n";
            if(popcount(i)<3)continue;
            int sum=0,mx=-1;
            for(int j=1;j<=n;j++){
                if((i>>(j-1))&1){
                    sum+=a[j],mx=max(mx,a[j]);
                }
            }
            if(sum>2*mx)ans++;
        }
        cout<<ans<<"\n";
    }
    // a_i==1 24
    // O(n+log)
    using tools::C;
    void sol2(int n){
        tools::C_init(n,p);
        // for(int i=1;i<=n;i++){
        //     cout<<C(n,i,p)<<"\n";
        // }
        ll ans=0;
        for(int i=3;i<=n;i++){
            //cout<<C(n,i,p)<<"\n";
            ans=(ans+C(n,i,p))%p;
        }
        cout<<ans<<"\n";
    }
	void main(){
        int n;
        cin>>n;
        bool sl2=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sl2&=a[i]==1;
        }
        if(n<=20){
            sol1(n);
        }else if(sl2){
            sol2(n);
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	hcx::main();
	return 0;
}