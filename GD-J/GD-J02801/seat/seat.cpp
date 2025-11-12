#include<bits/stdc++.h>
using namespace std;
struct data
{
	int a;
	bool c;
}a[105];
bool cmp(data x,data y)
{
	return x.a>y.a;
}
int n,m,v;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	v=n*m;
	for(int i=1;i<=v;i++)
	{
		scanf("%d",&a[i].a);
		a[i].c=false;
	}
	a[1].c=true;
	sort(a+1,a+1+v,cmp);
	for(int i=1;i<=v;i++)
	{
		if(a[i].c)
		{
			int c=ceil(i*1.0/n);
			int r;
			if(c%2==1)
			{
				r=i%n;
				if(!r)
				{
					r=n;
				} 
			}
			else
			{
				r=n-(i%n)+1;
			}
			printf("%d %d",c,r);
			break;
		}
	}
	return 0;
}
