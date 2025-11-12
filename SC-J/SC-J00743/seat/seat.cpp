#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int chengji[N] = {};
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n * m; i++)
	{
		cin >> chengji[i];
	}
	
	int flag = chengji[0];
	int c = 0;
	int r = 0;
	int cnt = 0;
	sort(chengji, chengji + n * m, cmp);
	
	for(int i = 0; i < n * m; i++)
	{
		if(chengji[i] == flag)
		{
			cnt = i + 1;
			break;
		}
	}
	if(cnt % n == 0)
	{
		int flag2 = cnt / n;
		c = flag2;
		if(flag2 % 2 == 0)
		{
			r = 1;
			cout << c << " " << r;
			return 0;
		}
		else
		{
			r = n;
			cout << c << " " << r;
			return 0;
		}
	}
	int ans = cnt / n + 1;
	c = ans;
	if(ans % 2 == 0)
	{
		r = n - cnt % n + 1;
		cout << c << " " << r;
		return 0;
	}
	else
	{
		r = cnt % n;
		cout << c <<" " << r;
		return 0;
	}
	return 0;
}
