#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N],mp[15][15];
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int s=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int now=2,k=0;
	mp[1][1]=a[1];
	for(int j=1;j<=m;j++)
	{
		if(j%2==0)
		{
			for(int i=n;i>=1;i--)mp[i][j]=a[now],now++;
		}
		else
		{
			if(j==1)for(int i=2;i<=n;i++)mp[i][j]=a[now],now++;
			else for(int i=1;i<=n;i++)mp[i][j]=a[now],now++;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		if(mp[i][j]==s)
		{
			printf("%d %d",j,i);
			return 0;
		}
	}
	return 0;
}
