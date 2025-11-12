#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,a[N*N],ljn[N][N],r,c,t;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int u)
{
	if(u&1)
	{
		int res=(u-1)*m;
		for(int i=1;i<=n;i++)
		{
			if(a[res+i]==t)
			{
				printf("%d %d\n",u,i);
				return;
			}
		}
	}
	else
	{
		int res=(u-1)*m;
		for(int i=n;i>=1;i--)
		{
			if(a[res+n-i+1]==t)
			{
				printf("%d %d\n",u,i);
				return;
			}
		}
	}
	dfs(u+1);
}
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(0);
	return 0;
}