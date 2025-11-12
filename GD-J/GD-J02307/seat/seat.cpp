#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[205];
int n,m,ps[15][15];
bool cmp(pair<int,int>x,pair<int,int>y){return x>y;}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,k=1;
	while(j<=m)
	{
		if(j&1)
		{
			while(i<=n)
			{
				ps[i][j]=a[k++].second;
				i++;
			}
			i=n;
		}
		else
		{
			while(i>=1)
			{
				ps[i][j]=a[k++].second; 
				i--;
			}
			i=1;
		}
		j++;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ps[i][j]==1)
			{
				printf("%d %d",j,i);
				return 0;
			}
	return 0;
}
