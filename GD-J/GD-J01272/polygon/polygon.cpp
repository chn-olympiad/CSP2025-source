#include <bits/stdc++.h>
using namespace std;

const int M=998244353;
int n,ans,a[5100],dp[5100];

int qpow(int x,int p){
	int sum=1,mul=x;
	
	while(p){
		if(p&1)  sum=1ll*sum*mul%M;
		
		mul=1ll*mul*mul%M;
		
		p>>=1;
	}
	
	return sum;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i=1; i<=n; i++)  cin >> a[i];
	
	sort(a+1,a+n+1);
	
	dp[0]=1;
	
	for (int i=1; i<=n; i++){
		ans=(ans+qpow(2,i-1))%M;
		
		for (int j=0; j<=a[i]; j++)  ans=(ans-dp[j]+M)%M;
		
		for (int j=a[n]; j>=a[i]; j--)  dp[j]=(dp[j]+dp[j-a[i]])%M;
	}
	
	cout << ans;
	
	return 0;
}
