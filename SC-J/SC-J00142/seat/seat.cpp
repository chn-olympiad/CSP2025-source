#include<bits/stdc++.h>
using namespace std;
int a[100001];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[(i-1)*m+j]);
		} 
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			int l=(i%n==0?i/n:(i/n+1));
			printf("%d ",l);
			int h=(i%n==0?n:i%n);
			if(l%2==1)
			{
				printf("%d",h);
			}
			else printf("%d",n-h+1);
		}
	}
	return 0;
} 