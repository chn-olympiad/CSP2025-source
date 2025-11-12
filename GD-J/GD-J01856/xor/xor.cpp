#include<iostream>
#include<cstdio>
using namespace std;
const int N=5*1e5+5;
int n,k;
int a[N];
int s[N];
int x[N],y[N];
bool b[N];
int t;
int ans;
int dfs(int count)
{
	int re=count;
	for(int i=1; i<=t; ++i)
	{
		bool flag=true;
		for(int j=x[i]; j<=y[i]; ++j)
		{
			if(b[j]==true)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			for(int j=x[i]; j<=y[i]; ++j)
				b[j]=true;
			re=max(re,dfs(count+1));
			for(int j=x[i]; j<=y[i]; ++j)
				b[j]=false;
		}
	}
	return re;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1] xor a[i];
	}
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=i; j<=n; ++j)
		{
			if((s[j] xor s[i-1])==k)
			{
				++t;
				x[t]=i;
				y[t]=j;
			}
		}
	}
	ans=dfs(0);
	printf("%d",ans);
	return 0;
}
