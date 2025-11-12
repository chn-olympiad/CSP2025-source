#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,X=1,Y=1;
bool cnt;
struct Frisk
{
	int a,f;
}c[1001];
bool Chara(Frisk x,Frisk y)
{
	return x.a>y.a;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i].a;
		c[i].f=i;
	}
	sort(c+1,c+n*m+1,Chara);
	for(int i=1;i<=n*m;i++)
	{
		if(c[i].f==1) break;
		if(Y==n&&!cnt)
		{
			X++;
			cnt=1;
		}
		else if(Y==1&&cnt)
		{
			X++;
			Y=1;
			cnt=0;
		}
		else
		{
			if(!cnt) Y++;
			else Y--;
		}
	}
	cout<<X<<' '<<Y;
	return 0;
}