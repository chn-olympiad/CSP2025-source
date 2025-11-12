#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y)
{
	return (x>y)?1:0;
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
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id=1;
	int x=1,y=1;
	while(1)
	{
		while(x<=n)
		{
			if(a[id]==s)
			{
				printf("%d %d",y,x);
				return 0;
			}
			id++;
			x++;
		}
		x--;
		y++;
		if(y>m)
		{
			return 0;
		}
		while(x>0)
		{
			if(a[id]==s)
			{
				printf("%d %d",y,x);
				return 0;
			}
			id++;
			x--;
		}
		x++;
		y++;
	}
	return 0;
}
