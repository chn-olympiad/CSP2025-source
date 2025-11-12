#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)

typedef long long ll;
typedef double db;

using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int N;
    cin>>N;
    vector<int> A(N+1,0);
    rep(i,1,N) cin>>A[i];
    const ll mod=998244353;
    if(N<=20)
    {
        // 直接用 n 位蛮力。0~2^n-1
        ll ans=0;
        rep(mask,0,(1<<N)-1)
        {
            int sum=0,_max=0;
            rep(i,0,N-1)
                if((mask>>i)&1)
                    sum+=A[i+1],_max=max(_max,A[i+1]);
            if(sum>2*_max) ans++;
        }
        cout<<ans<<endl;
    }
    else // all 1
    {
        // ans=2^N-1-N-C(N,2)=2^N-1-N-N(N-1)/2
        ll ans=1;
        rep(i,1,N) ans*=2,ans%=mod;
        ans-=(1+N+N*(N-1)/2);
        ans=(ans+mod)%mod;
        cout<<ans<<endl;
    }
}