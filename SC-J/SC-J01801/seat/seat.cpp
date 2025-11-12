#include<bits/stdc++.h>
using namespace std;
#define L long long
#define S string
#define B bool
#define C char
#define I cin
#define O cout
#define V vector
B cmp(L a,L b)
{
	return a>b;
}
signed main()
{
	//唯一识别码：qwertydfjifjgdjuvhdsihcudbsbsbhz
	ios::sync_with_stdio(0);
	I.tie(0);
	O.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	L l,r,rep;
	I>>r>>l;
	V<L> a(l*r+1);
	cin>>a[0];
	rep=a[0];
	for(L i0=1;i0<=l*r-1;i0++){I>>a[i0];}
	sort(a.begin(),a.end(),cmp);
	L add;
	for(L i0=1;i0<=l*r-1;i0++)
	{
		if(rep==a[i0])
		{
			add=i0;
			break;
		}
	}
	O<<add/r+1;
	if((add/r+1)%2==1)
	{
		cout<<' '<<add%r+1;
	}
	else
	{
		cout<<' '<<r-add%r;
	}
	return 0;
}