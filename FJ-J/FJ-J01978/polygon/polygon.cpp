#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
int n,a[5001],sum[5001],dp[5001][5001];
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}return res;
}
signed main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) dp[0][i]=(i+1)*i/2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]+=dp[i-a[j]][i-1];
		}
	}
	for(int i=1;i<=n;i++,cout<<endl) for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";
}
