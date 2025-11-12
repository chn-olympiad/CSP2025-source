#include <fstream>
#include <cstdio>
typedef long long ll;
const ll N=1e6+10;
int s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k; scanf("%lld%lld",&n,&k);
	ll ans=0;
	bool flagA=1;
	for(int i=1; i<=n; i++){
		scanf("%d",&s[i]);
		if(s[i]!=1) flagA =0;
	}
	if(flagA){
		ll t=n/2;
		for(int i=t; i>=1; i--){
			ans+=i;
		}
		printf("%lld",ans);
	}
	else {
		for(int i=1; i<=n;){
			if(s[i]==k){
				ans++; i++; continue;
			}
			ll temp=s[i];
			for(int j=i+1; j<=n; j++){
				temp=temp^s[j];
				if(temp==k){
					i=j+1;
					ans++; break;
				}
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
