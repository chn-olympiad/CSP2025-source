#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, ansx, ansy;
	cin >> n >> m;
	int nm = n * m;
	int a[nm];
	for(int i = 0; i < nm; i ++) cin >> a[i];
	int r = a[0], pos;
	sort(a, a + nm);
	for(int i = 0; i < nm; i ++)
	{
		if(a[i] == r)
		{
			pos = nm - i;
			break;
		}
	}
	ansx = (pos + n - 1) / n;
	int k = pos % n;
	if(k == 0)
	{
		if(ansx % 2) ansy = n;
		else ansy = 1;
	}
	else
	{
		if(ansx % 2) ansy = k;
		else ansy = n - k + 1;
	}
	cout << ansx << ' ' << ansy;
	return 0;
}
