#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m;

struct Node 
{
	int t;
	bool b;
};
Node a[105];
bool cmp (Node a,Node b)
{
	return a.t>b.t;
}
int x,y;
bool f;
signed main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>a[1].t;
	a[1].b=1;
	for(int i=2;i<=n*m;++i)
		cin>>a[i].t,a[i].b=0;
	sort(a+1,a+n*m+1,cmp);
	x=y=1;
	f=0;
	for(int i=1;i<=n*m;++i)
	{
		if(a[i].b) 
		{
			cout<<y<<" "<<x;
			break;
		}
		if(f)
			if(x==1) ++y,f=0;
			else --x;
		else
			if(x==n) ++y,f=1;
			else ++x;
	}
	return 0;
}
