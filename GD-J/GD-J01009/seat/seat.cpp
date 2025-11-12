#include<bits/stdc++.h>
using namespace std;
const int M=110;
int n,m,a[M],s,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(register int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])++s;
	}
	x=y=1;
	while(s--)
	{
		if(y&1)
		{
			++x;
			if(x>n)
			{
				++y;
				x=n;
			}
		}
		else
		{
			--x;
			if(x<1)
			{
				++y;
				x=1;
			}
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
