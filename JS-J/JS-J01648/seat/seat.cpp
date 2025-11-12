#include <bits/stdc++.h>
using namespace std;

const int N = 115;
int n,m,xr,p,c,r;
int a[N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)
	{
		cin >> a[i];
	}
	xr = a[1];
	sort(a+1,a+1+n*m);
	p = lower_bound(a+1,a+1+m*n,xr)-a;
	p = n*m-p+1;
	c = ceil((double)p/n);
	int tmp = p%(2*n);
	if(tmp==0)    r = 1;
	else if(tmp<=n)
	{
		r = tmp;
	}
	else
	{
		r = 2*n-tmp+1;
	}
	cout << c << " " << r << endl;
	return 0;
}
