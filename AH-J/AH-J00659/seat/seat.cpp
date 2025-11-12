#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005],dx=1;
bool cmp(int x,int y)
{return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1;
	for(int u=1;u<=n*m;u++)
	{
		if (a[u]==k){cout<<j<<" "<<i; return 0;}
		if (i+dx<=n&&i+dx>=1) i+=dx;
		else dx=-dx,j++;
	}
	return 0;
}
