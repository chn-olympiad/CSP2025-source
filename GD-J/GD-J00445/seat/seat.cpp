#include <bits/stdc++.h>

using namespace std;
long long n,m,a[105],xr,now;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		a[i]=-a[i];
	}
	xr=-a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				now++;
				if(xr==-a[now]){cout<<i<<" "<<j;return 0;}
			}
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				now++;
				if(xr==-a[now]){cout<<i<<" "<<j;return 0;}
			}
		}
	}
	return 0;
}
