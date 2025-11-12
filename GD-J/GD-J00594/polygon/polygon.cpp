#include <iostream>
#include <algorithm>

using namespace std;

const int N=5015,MOD=998244353;

int n,a[N];
int m;
long long dp[N];


int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],m=max(m,a[i]);
	sort(a+1,a+n+1);
	
	long long ans=0;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=m+1;j++) ans+=dp[j];
		ans%=MOD;
		
		for(int j=m+1;j+a[i]>m;j--) dp[m+1]+=dp[j];
		dp[m+1]%=MOD;
		
		for(int j=m;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%MOD;
	}
	
	cout<<ans;
	
	return 0;
}
