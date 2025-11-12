#include <iostream>
#include <cstdio>
using namespace std;
long long n,k,a[500010],b[1010][1010],maxn=0,sum=0;
bool s[500010];
long long dp[1010][1010]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==k)sum++,s[i]=1;
	}
	for (int i=1;i<=n;i++)
	{
		long long cnt=0;
		for (int j=i;j<=n;j++)b[i][j]=cnt^a[j],cnt^=a[j];
	}
	/*for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)cout<<b[i][j]<<' ';
		cout<<endl;
	}*/
	int qleft=0;
	for (int i=1;i<=n;i++)
	{
		long long cnt=0;
		if (qleft==0)qleft=i;
		if (s[i]==1)
		{
			if (qleft!=0)sum+=dp[qleft][i-1];
			qleft=0;
			maxn=0;
			continue; 
		} 
		int l,r;
		for (l=i,r=i;s[r]!=1&&s[l]!=1&&l<=n&r<=n;)
		{
			if (b[l][r]==k)
			{
				dp[l][r]=1;
				//cout<<l<<' '<<r<<"true\n";
				cnt++,l=r+1;
				r=l;
			}
			dp[i][r]=cnt;
			r++;
		}
		dp[i][r-1]=cnt;
		if (i!=qleft)dp[qleft][r-1]=cnt+dp[qleft][i-1];
		//cout<<cnt<<' '<<dp[qleft][i-1]<<' '<<dp[qleft][r-1]<<endl;
		for (int j=qleft;j<r;j++)dp[qleft][j]=max(dp[qleft][r-1],dp[qleft][r-1]);
		//maxn=max(maxn,dp[qleft][r-1]);
	}
	if (qleft!=0)sum+=dp[qleft][n];
	cout<<sum;
	return 0;
}
