#include<bits/stdc++.h>
#define ll long long
using namespace std;

namespace A{
	
	ll read(){
		ll x=0,f=1;char c;c=getchar();
		while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
		while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
		return x*f;
	}
	
	ll n,a[5001][5001],xo=998244353;
	
	void S(ll mx){
		a[0][1]=1;
		for(ll i=1;i<=mx;i++){
			for(ll j=1;j<=i+1;j++){
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
	}
	
	void Solve(){
		n=read();
		S(n);
		ll ans=0;
		for(ll j=4;j<=n+1;j++){
			ans=(ans+a[n][j])%xo;
		}printf("%lld",ans);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	A::Solve();
	return 0;
} 
