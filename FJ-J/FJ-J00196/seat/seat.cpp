#include <bits/stdc++.h>
using namespace std;
int a[105],n,m;
int main()
{
	//zxr
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	n*=m;
	for (int i=1;i<=n;i++ )cin >> a[i];
	int ai=a[1],pos,x,y,num=1;
	sort (a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		if (a[i]==ai)
		{
			pos=i;
			break;
		}
	}
	pos=n-pos+1;
	n/=m;
	y=pos/m+1;
	x=pos%n;
	if (x==0)
	{
		if (y-1%2==0)cout << y-1 << " "<< 1;
		else cout << y-1 << " " << n;
	}
	else
	{
		if (y%2==0) cout << y <<  " " << pos-n*y+y;
		else cout << y << " " << x;
	}
	return 0;
}
