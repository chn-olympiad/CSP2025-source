#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x=1,y=1,zl=1,f=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	f=a[1];
	sort(a+1,a+1+n*m,[](int x,int y)
	{
		return x>y;
	});
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==f)
		{
			printf("%d %d",y,x);
			return 0;
		}
		if(x==n&&zl==1)
		{
			y++;
			zl=-1;
		}
		else if(x==1&&zl==-1)
		{
			y++;
			zl=1;
		}
		else
			x+=zl;
	}
	return 0;
}
