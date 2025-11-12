#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],C[5001][5001],mod=998244353,allone=1,ans=0;
void Init()
{
	for(int i=0;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			allone=0;
		}
	}
	Init();
	if(allone)
	{
		for(int i=3;i<=n;i++)
		{
			for(int j=2;j<i;j++)
			{
				ans=(ans+C[i-1][j])%mod;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<(1<<n);i++)
	{
		long long sum=0,maxa=0;
		for(int j=0;j<n;j++)
		{
			if(i>>j&1)
			{
				maxa=max(maxa,a[j+1]);
				sum+=a[j+1];
			}
		}
		if(sum>2*maxa)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
