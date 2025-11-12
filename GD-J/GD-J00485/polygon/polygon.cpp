#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5005;
const ll mod=998244353;
ll dp[505][50005];
ll dp1[5005][5005];
int a[maxn];
int n;
ll ans=0;
int flag=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
	}
	sort(a+1,a+1+n);
	if(flag&&n>500){
		for(int i=0;i<=n;i++)dp1[i][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<a[i];j++)dp1[i][j]=dp1[i-1][j];
			for(int j=a[i];j<=5005-5;j++){
				dp1[i][j]=(dp1[i-1][j-a[i]]+dp1[i-1][j])%mod;
	//			cout<<dp[i][j]<<' ';
			}
	//		cout<<endl;
		}
		for(int i=3;i<=n;i++){
			for(int j=a[i]+1;j<5005-5;j++){
				ans+=dp1[i-1][j];
				ans%=mod;
			}
		}
		cout<<ans%mod; 
		return 0;
	}
	for(int i=0;i<=n;i++)dp[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<a[i];j++)dp[i][j]=dp[i-1][j];
		for(int j=a[i];j<=50005-5;j++){
			dp[i][j]=(dp[i-1][j-a[i]]+dp[i-1][j])%mod;
//			cout<<dp[i][j]<<' ';
		}
//		cout<<endl;
	}
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<50005-5;j++){
			ans+=dp[i-1][j];
			ans%=mod;
		}
	}
	cout<<ans%mod; 
}
