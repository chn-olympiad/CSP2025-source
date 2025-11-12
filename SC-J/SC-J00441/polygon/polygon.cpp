#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
bool f[5005];
void dfs(int sum,int k,int cs,int j)//已累计的和，准备累计的和的下表
{
	for(int i=j;i<k;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			if(sum+a[i]>2*a[k]&&cs>=2)
			{
				ans++;
				ans%=998224353;
			}
			dfs(sum+a[i],k,cs+1,i+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		f[i]=1;
		dfs(a[i],i,1,1);
		f[i]=0;
	}
	ans%=998224353;
	printf("%lld",ans);
	return 0;
}