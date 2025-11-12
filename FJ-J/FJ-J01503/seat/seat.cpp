#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,ex,dx;
int a[10086];
int dfs(int left,int right)
{
	int mid=(left+right)/2;
	if(a[mid]==ex)
		return mid;
	else if(a[mid]>ex)
	{
		return dfs(left,mid);
	}
	else
	{
		return dfs(mid,right);
	}
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
	ex=a[1];
	sort(a+1,a+n*m+1);
	if(ex==a[n*m])
	{
		printf("1 1");
	}
	else
	{
		dx=n*m+1-dfs(1,n*m);
		//printf("%d",dx);
		c=dx/n+1;
		if(dx%n==0)
		{
			c--;
			r=n;
			printf("%d %d",c,r);
		}
		else
		{
			if(c%2==0)r=n-dx%n+1;
			else r=dx%n;
			printf("%d %d",c,r);
		}
	}
	return 0;
}

