#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
#define N 505
using namespace std;
bool s[N];
char c[N];
ll n,m,ans,Sum,a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,c+1);
	for(ll i=1;i<=n;i++)
		s[i]=(c[i]=='1'),Sum+=s[i];
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n<=11){
		ll p[15];
		for(ll i=1;i<=n;i++) p[i]=i;
		do{
			ll sum=0;
			for(ll i=1;i<=n;i++)
				if(a[p[i]]<=sum||!s[i]) sum++;
			ans+=(n-sum>=m);
		}while(next_permutation(p+1,p+n+1));
		printf("%lld",ans%mod);
		return 0;
	}
	if(Sum==n){
		ll k=0;
		for(ll i=1;i<=n;i++) k+=(a[i]==0);
		ans=1;
		for(ll i=1;i<=n;i++)
			(ans*=i)%=mod;
		printf("%lld",ans);
	}
	if(Sum==0){puts("0");return 0;}
	return 0;
}
