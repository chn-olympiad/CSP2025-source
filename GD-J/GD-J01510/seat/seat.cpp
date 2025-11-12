#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, cnt = 1;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i ++)
	{
		cin >> a[i];
		if(a[i] > a[1]) cnt ++;
	}
	if(n == 1)
	{
		cout << cnt << ' ' << 1;
	}
	else if(m == 1)
	{
		cout << 1 << ' ' << cnt;
	}
	else if(m <= 2 && n <= 2)
	{
		if(cnt == 1) cout << 1 << ' ' << 1;
		else if(cnt == 2) cout << 1 << ' ' << 2;
		else if(cnt == 3) cout << 2 << ' ' << 2;
		else if(cnt == 4) cout << 2 << ' ' << 1;
	}
	else
	{
		int h;
		if(cnt % n == 0) h = cnt / n;
		else h = cnt / n + 1;
		if(h % 2 == 1)
		{
			int x = (h-1)*n;
			cnt -= x;
			for(int i = 1; i <= n; i ++)
			{
				if(cnt == 1)
				{
					cout << h << ' ' << i;
					break;
				}
				cnt --;
			}
		}
		else
		{
			int x = (h-1)*n;
			cnt -= x;
			for(int i = n; i >= 1; i --)
			{
				if(cnt == 1)
				{
					cout << h << ' ' << i;
					break;
				}
				cnt --;
			}
		}
	}
	return 0;
}
