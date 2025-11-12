#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
long long maxx=0;
void dfs(int x,int a1,int b1,int c1,long long sum,int n)
{
	if(x>n)
	{
		maxx=max(maxx,sum);
		return ;
	}
	if(a1<n/2)
	{
		dfs(x+1,a1+1,b1,c1,sum+a[x],n);
	}
	if(b1<n/2)
	{
		dfs(x+1,a1,b1+1,c1,sum+b[x],n);
	}
	if(c1<n/2)
	{
		dfs(x+1,a1,b1,c1+1,sum+c[x],n);
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		maxx=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		dfs(1,0,0,0,0,n);
		printf("%lld\n",maxx);
	}
	return 0;
}
