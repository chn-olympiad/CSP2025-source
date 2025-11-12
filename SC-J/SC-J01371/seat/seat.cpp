#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[110];
int n,m,vl;
bool comp(int l,int r)
{
	return l>r;
}
int change(int x)
{
	if(x==1)
	{
		return -1;
	}
	return 1;
}
int main()
{
	freopen("r","seat.in",stdin);
	freopen("w","seat.out",stdout);
	int i;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	vl=a[1];
	sort(a+1,a+n*m+1,comp);
	int x=1,y=1,now=a[1],id=1,op=1;
	while(now>vl)
	{
		if(now==vl)
		{
			break;
		}
		if(y+op>n||y+op<1)
		{
			op=change(op);
			x++;
		}
		else
		{
			y+=op;
		}
		now=a[++id];
	}
	cout<<x<<' '<<y;
	return 0;
}