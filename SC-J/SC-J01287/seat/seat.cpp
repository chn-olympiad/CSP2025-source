#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[101];
int di;
int x,y,l,r;
int b,t=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	y=m,r=m;
	if(m%2==0)
		x=0,l=0,di=1;
	else
		x=n+1,l=n+1,di=-1;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i]);
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		x+=di;
		if(x==l)
		{
			y--;
			if(x==1)
				di=1;
			else
				di=-1;
		}
		else
			if((x==n&&(y<m||n%2==0))||(x==1&&(y<m||n%2==1)))
				di=0;
		t++;
		
		if(a[t]==b)
		{
			printf("%d %d",y,x);
			return 0; 
		}
		l=x,r=y;
	}
	return 0;
} 