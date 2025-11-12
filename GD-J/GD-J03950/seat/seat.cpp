#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,t,i;
int a[1010];
bool cmp(int x,int y)
{
	return x>y;
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
	t=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	x=0,y=1;
	while(1)
	{
		i++;
		if(y%2!=0)
		{
			x++;
			if(x>n)
			{
				x=n;
				y++; 
			}
		}
		else if(y%2==0)
		{
			x--;
			if(x<1)
			{
				x=1;
				y++;
			}
		}
		if(a[i]==t)
		{
			printf("%d %d",y,x);
			return 0;
		}
	}
	return 0;
}
