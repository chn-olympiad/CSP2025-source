#include <bits/stdc++.h>
using namespace std;
#define N 5010
#define M 998244353
int n;
long long a[N],f[N*N],q[N],ans=0,maxn=0;
bool flag=0;
int main()
{
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)flag=1;
	}
	if(flag==0)
	{
		for(int i=n;i>=3;i--)
		{
			for(int j=1;j<=n-i+1;j++)
			{
				ans+=j;
				ans%=M;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]!=a[i])
		{
			for(int j=maxn;j>=0;j--)
			{
				if(j>a[i])
				{
					long long d=1;
					ans=(ans+f[j]*(q[a[i]]+1))%M;
				}
			}
		}
		for(int j=maxn;j>=0;j--)
		{
			f[j+a[i]]+=(f[j]+q[j]);
			if(j>a[i]&&a[i+1]==a[i])ans-=f[j];
		}
		q[a[i]]++;
		maxn=maxn+a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
