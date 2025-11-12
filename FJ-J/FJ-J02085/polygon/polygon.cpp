#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int mod=998244353;
int n,sum,ans;
int a[N],dp[50005],tmp[50005]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=0;j--){
			dp[j+a[i]]+=dp[j];
			dp[j+a[i]]%=mod;
		}
		sum+=a[i];
		if(i>=3){
			for(int j=a[i]*2+1;j<=sum;j++)
				ans+=dp[j]-tmp[j],ans%=mod;			
		}
		for(int j=1;j<=sum;j++)
			tmp[j]=dp[j];
//		for(int j=1;j<=sum;j++)
//			printf("(%lld,%lld)",j,dp[j]);
//		cout<<'\n'<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}


