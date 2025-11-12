#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int q,int p)
{
	return q>p;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int k=a[1],x=0,y=0;
	sort(a+1,a+n*m+1,cmp);
	if(n==1&&m==1)
	{
		printf("%d",a[1]);
	}
	else if(n==1)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(a[i]==k)
			{
				printf("%d 1",i);
				return 0;
			}
		}
	}
	else if(m==1)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(a[i]==k)
			{
				printf("1 %d",i);
				return 0;
			}
		}
	}
	else
	{
		for(int i=1;i<=n*m;i++)
		{
			if(a[i]==k)
			{
				cout<<((i-1)/m+1)<<' '<<(i%(2*n));
				return 0;
			}
		}
	}
	return 0;
}
