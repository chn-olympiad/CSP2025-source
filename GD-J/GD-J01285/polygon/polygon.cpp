#include<bits/stdc++.h>
using namespace std;
const int maxn = 6000;
long long n,a[maxn],b[maxn],dp[maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(dp,0,sizeof(dp));
	for(long long i = 1;i<=n;i++){
		cin >> a[i];
	}
	
	sort(a,a+n+1);
	for(long long i = 1;i<=n;i++){
		b[i] = b[i-1]+a[i];
	}
	if(b[3]>(a[3]*2)){
		dp[3] = 1;
	}
	if(n == 3){
		cout << dp[3]%998244353;
		return 0;
	}
	else{
		long long ans = 0;
		long long num = 1,sum = 1;
		for(long long i = 3;i<n;i++){
			for(long long j = 1;j<=i;j++){
				sum*=(n-j+1);
				num*=j;
			}
			ans = (ans+(sum/num))%998244353;
			num = 1;sum = 1;
		}
		cout << (ans+1)%998244353;
	}
	return 0;
}
