#include<bits/stdc++.h>
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
int n,m,b,f=1,a[106];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,[&](int x,int y)
	{
		return x>y;
	});
	int x=1,y=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			cout<<x<<" "<<y;
			break;
		}
		y+=f;
		if(y>n)
		{
			x++;
			y=n;
			f=-1;
		}
		if(y<1)
		{
			x++;
			y=1;
			f=1;
		}
	}
	return 0;
}