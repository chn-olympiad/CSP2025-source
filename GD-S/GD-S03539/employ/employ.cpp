#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,c[505];
bool s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	char c=getchar();
	ll pd=0;
	for(ll i=1;i<=n;i++){
		while(c!='0'&&c!='1'){
			c=getchar();
		}
		s[i]=(c=='1');
		pd+=s[i];
	}
	if(pd==n){
		ll ans=1;
		for(ll i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	}
	else if(pd<m){
		printf("0");return 0;
	}
	return 0;
}
