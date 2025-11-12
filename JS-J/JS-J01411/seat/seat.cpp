# include <bits/stdc++.h>
using namespace std;

int n,m,a[105],x,r,cnt,lie,hang,lun;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> r;
	a[r]++;
	for (int i = 2;i <= n*m; i++)
	{
		cin >> x;
		a[x]++;
	}
	
	for (int i = 100; i >= 1; i--)
	{
		cnt++;
		if (i==r)break;
	}
	if (cnt%(n*2)==0)
	{
		lun = cnt/(n*2);
	}
	else lun = cnt/(n*2)+1;
	lie = lun*2;
	cnt -= (lun-1) * (n*2);
	if (cnt<=n)
	{
		lie--;
		hang = cnt;
	}
	else hang = 2*n-cnt+1;
	cout << lie <<" " << hang;
	return 0;
}
