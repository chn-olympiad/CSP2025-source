#include<bits/stdc++.h>
#define N 20
using namespace std;
int n,m,cnt;
int hh=0,ll=1;
struct node
{
	int cj;
	int id;
}f[N*N];
bool cmp(node x,node y)
{
	return x.cj>y.cj;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++)
	{
		cin>>f[i].cj;
		f[i].id=i;
	}
	sort(f+1,f+cnt+1,cmp);
	int o=1;
	for(int i=1;i<=cnt;i++)
	{
		hh+=o;
		if(hh>n)
		{
			hh=n;
			ll++;
			o=-o;
		}
		if(hh<1)
		{
			hh=1;
			ll++;
			o=-o;
		}
		if(f[i].id==1)
		{
			cout<<ll<<" "<<hh;
			return 0;
		}
	}
}
//2 2
//99 100 97 98
//
//2 2
//98 99 100 97
