#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool b[5005],f;
int a[5005],c[5005];
long long sum;
const int mod=998244353;
void dfs(int k)
{
	if(k>3)
	{
		sum=0;
		f=1;
		for(int i=1;i<k;i++) sum+=c[i];
		for(int i=1;i<k;i++)
		{
			if(sum-c[i]<=c[i])
			{
				f=0;
				break;
			}
		}
		if(f)
		{
			ans=(ans+1)%mod;
		}
	}
	for(int i=k+1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			c[k]=a[i];
			dfs(k+1);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dfs(0);
	printf("%d",ans);
	return 0;
}
