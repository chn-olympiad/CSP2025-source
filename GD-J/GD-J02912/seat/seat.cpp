#include<bits/stdc++.h>
using namespace std;
int a[500000];
int z;
int t[500][500];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	z=a[1];
	sort(a+1,a+1+n*m,cmp);
	int tmp=0;
	for(int i=1;i<=m;i++)//ÁÐ 
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)//ÐÐ 
			{
				t[j][i]=a[++tmp];
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				t[j][i]=a[++tmp];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{ 
			if(t[i][j]==z)
			{
				printf("%d %d",j,i);
				return 0;
			}
		}
	}
	return 0;
}
