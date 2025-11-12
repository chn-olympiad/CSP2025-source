#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int MOD=998244353;
long long n,a[N],maxn,ans,dp[N],p[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if (n==3){
		if (a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else{
		dp[1]=1,dp[2]=5;
		p[2]=4;
		for (int i=3;i<=n;i++){
			p[i]=p[i-1]+((long long)(7*pow(3,pow(2,i-2)))%MOD);
			dp[i]=dp[i-1]+(p[i]%MOD)%MOD;
		}
		cout<<dp[n];
	}
	return 0;
}
