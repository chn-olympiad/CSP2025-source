#include<bits/stdc++.h>
using namespace std;
int n,m,num;
int b[15][15],a[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			b[i][j]=a[k++];
		if(i==m) break;
		i++;
		for(int j=n;j>=1;j--)
			b[i][j]=a[k++];
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(b[i][j]==num)
			{
				printf("%d %d",i,j);
				return 0;
			}
	return 0;
}
