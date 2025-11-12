#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll p=998244353;
ll n,m,sum;
string s;
ll a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin >> s;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++){
		if(a[i]!=0) sum++;
	} 
	ll ans=1;
	if(n==m){
		ll f=0;
		for(ll i=0;i<s.size();i++){
			if(s[i]=='0') f=1;
		}
		for(ll i=1;i<=n;i++){
			ans*=i;
			ans%=p;
		}
		if(f==1 || sum!=n) printf("0");
		else printf("%lld",ans);
	}else{
		for(ll i=1;i<=n;i++){
			ans*=i;
			ans%=p;
		}
		printf("%lld",ans);
	}
	return 0;
}
