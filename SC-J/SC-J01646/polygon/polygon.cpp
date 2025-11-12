#include<bits/stdc++.h>
using namespace std;
const int N=5e3+2;
const long long mod=998244353;

int n;
long long a[N];
long long dp[N*N],num;
long long ans,lin;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],num+=a[i];
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		for(int j=num;j-a[i]>=0;j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
		dp[a[i]]++;
		for(int j=a[i]*2+1;j<=num;j++){
			ans=(ans+dp[j])%mod;
		}
		
	}
	
	cout<<ans;
	return 0;
} 
/*
5
1 2 3 4 5

5
2 2 3 8 10


*/
