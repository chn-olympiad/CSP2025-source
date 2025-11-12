#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+7;
void in(ll &num){
	ll k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k=10*k+c-'0';
		c=getchar();
	}
	num=k*f;
}
ll n,k,sum[N],dp[N],maxn[N];
ll a[N],tp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	in(n),in(k);
	for(ll i=1;i<=n;i++){
		in(a[i]);
		sum[i]=a[i]^sum[i-1];
	}
	for(ll i=1;i<=n;i++){
		ll t=k^sum[i];
		if(tp[t]!=0||t==0){
			dp[i]=maxn[tp[t]]+1;
		}
		if(a[i]==k){
			dp[i]=maxn[i-1]+1;
		}
		tp[sum[i]]=i;
		maxn[i]=max(maxn[i-1],dp[i]);
	}
	printf("%lld",maxn[n]);
	return 0;
}

