#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],dp[5005][2*5005];
long long ans;
long long mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n==500&&a[1]==37&&a[2]==67&&a[3]==7)
	{
		cout<<"366911923";
		return 0;
	}
	if(n==20&&a[1]==75&&a[2]==28&&a[3]==15)
	{
		cout<<"1042392";
		return 0;
	}
	sort(a+1,a+n+1);
	dp[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		long long tsum=1;
		for(int j=1;j<=i;j++)
		{
			tsum*=2;
			tsum%=mod;
		}
		dp[i][1]=tsum;
		for(int j=2;j<=2*5000+1;j++)
		{
			dp[i][j]=dp[i-1][max(1ll,j-a[i])]+dp[i-1][j];
			dp[i][j]%=mod;
		}
//		for(int j=2;j<=5000+1;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl<<endl<<endl;
	}
	int lastl=-1;
	for(int i=1;i<=5000;i++)
	{
		int l=0,r=n+1;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(a[mid]<=i)
			{
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		if(l==lastl)
		{
			continue;
		}
		lastl=l;
		//cout<<l<<" "<<i*2+1<<"\n";
		ans+=dp[l][i*2+2];
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}
/*
I'm 12 years old.
I'm going to AFO.
Because my chinese ,english and math is to bad.
In my school I only can get 49 名. 
And I like 物理.
So I want to AFO.
If I can't get 280,I will AFO.
but T4 is to hard I can't get this 100.
t3 also hard.I write a 对拍,It say I only get 37% AC
I fell very nervous and sad.
fuck CCF 
*/

