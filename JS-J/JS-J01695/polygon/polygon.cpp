#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int P = 998244353;

ll qpow(ll base,ll k){
	ll res=1;
	while(k){
		if(k&1)
			res=(res*base)%P;
		base=(base*base)%P;
		k>>=1;
	}
	return res;
}

const int N = 5000+5;

int dp[N],n;
int a[N];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ll ans=0;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		ll cnt=qpow(2,i-1);
		for(int j=0;j<=a[i];j++)
			cnt=(cnt-dp[j]+P)%P;
		ans=(ans+cnt)%P;
		for(int j=5000;j>=a[i];j--)
			dp[j]=(dp[j]+dp[j-a[i]])%P;
	}
	printf("%lld\n",ans);
	return 0;
}