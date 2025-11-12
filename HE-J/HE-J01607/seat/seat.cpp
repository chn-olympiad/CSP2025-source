#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m*n;i++)
	{
		scanf("%d",&a[i]);
	}
	int x=a[1];
	int y;
	for(int i=1;i<=n*m;i++)
	{
		int maxid=i;
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[j]>a[maxid])
			{
				maxid=j;
			}
		}
		swap(a[i],a[maxid]);
	}
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==x)
		{
			y=i;
		}
	}
	int p=(y-1)/m+1;
	int q;
	int w;
	w=y%n;
	if(w==0)
	{
		w=n;
	}
	printf("%d ",p);
	if(p%2==0)
	{
		q=n-w+1;
	}
	else
	{
		q=w;
	}
	printf("%d ",q);
	return 0;
}
