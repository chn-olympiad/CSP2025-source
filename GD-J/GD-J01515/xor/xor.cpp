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
	ll n,k,a[500005],b=1;
	void Solve(){
		n=read();k=read();
		for(ll i=1;i<=n;i++){
			a[i]=read();
			if(a[i]==0)b=2;
		}
		if(b==1){
			if(n<=2&&k==0){
				if(n==1)printf("0");
				if(n==2)printf("1");
			}else{
				printf("%lld",n/2);
			}
		}
		if(b==2){
			if(k<=1){
				if(k==0){
					ll ans=0;
					for(ll i=1;i<=n;i++){
						if(a[i]==0)ans++;
						if(a[i]==1&&a[i]==a[i-1]){
							ans++;
						}
					}
					printf("%lld",ans);
				}
				if(k==1){
					ll ans=0;
					for(ll i=1;i<=n;i++){
						if(a[i]==1)ans++;
					}printf("%lld",ans);
				}
			}
		}
	}
}


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	A::Solve();
	return 0;
} 
