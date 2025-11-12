#include <bits/stdc++.h>
using namespace std;

const int N=10+5,M=10+5;

int s;

struct Edge
{
	int a;
	bool flag=false;
}e[N*M];

bool cmp(Edge x,Edge y)
{
	return x.a>y.a;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>e[i].a;
		if (i==1)
		{
			e[i].flag=true;
		}
	}
	sort(e+1,e+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if (e[i].flag)
		{
			s=i;
			break;
		}
	}
	int u=ceil(s*1.0/n),v,ansm,ansn;
	ansm=u;
	if (u==1)
	{
		v=s;
	}
	else
	{
		v=s%n;
	}
	if (v==0)
	{
		if (u%2==0)
		{
			ansn=1;
		}
		else
		{
			ansn=n;
		}
	}
	else
	{
		if (u%2==0)
		{
			ansn=n-v+1;
		}
		else
		{
			ansn=v;
		}
	}
	cout<<ansm<<" "<<ansn<<"\n";
	return 0;
}
