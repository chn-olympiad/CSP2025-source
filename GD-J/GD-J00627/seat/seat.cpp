#include<bits/stdc++.h>
using namespace std;
int n,m,bz=0,l,h;
struct node
{
	int val,id;
}a[205];
bool cmp(node x,node y)
{
	return x.val>y.val;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			bz=i;
			break;
		}
	}
	if(bz%n==0)
	{
		l=bz/n;
	}
	else
	{
		l=bz/n+1;
	}
	if(l%2==1)
	{
		if(bz%n==0)
		{
			h=n;
		}
		else
		{
			h=bz%n;
		}
	}
	else
	{
		if(bz%n==0)
		{
			h=1;
		}
		else
		{
			h=n-(bz%n)+1;
		}
	}
	printf("%d %d",l,h);
	return 0;
}
