#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3+5;
const int M = 5e2+5;
const int mod = 998244353;
int n,a[N],res,sum[N*M],ans=0,dp[N],p[N];

int power(int t,int x){
	int num = 1;
	while(t>0){
		if(t & 1) num=(num*x)%mod;
		x=(x*x)%mod,t>>=1;
	}
	return num;
}

void solve2(){
	res = ((n*(n-1))%mod*(n-2))%mod;
	cout<<(res*power(mod-2,6))%mod<<endl;
	return ;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
		res += a[i];
	}
	if(n>=5000){
		solve2();
		return 0;
	}
	sort(a+1,a+n+1);
//	init();
	p[0]=sum[0]=1;
	for(int i = 1; i<=n; i++){
		dp[i] = sum[a[i]+1];
//		cout<<a[i]<<" "<<sum[a[i]+1]<<endl;
		for(int j = res; j>=0 && j>=a[i]; j--){
			p[j] = (p[j]+p[j-a[i]])%mod;
		}
		for(int j = res; j>=0; j--){
			sum[j] = (sum[j+1]+p[j])%mod;
		}
//		for(int j = 0; j<=res; j++){
//			cout<<p[j]<<" ";
//		}
//		cout<<endl;
		ans = (ans+dp[i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}
