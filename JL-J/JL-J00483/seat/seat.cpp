#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int fen[N];
int zuo[N][N];
int hao[N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> fen[i];
	}
	int w = fen[1];
	int x, r, hang, lie, ans1, ans2;
	for(int i = 1; i <= n * m; i++)
	{
		if(fen[i] < fen[i + 1] && i + 1 <= n * m)
			{
				x = fen[i];
				fen[i] = fen[i + 1];
				fen[i + 1] = x;
			}
	}
	for(int i = 1; i <= n * m; i++)
	{
		if(fen[i] < fen[i + 1] && i + 1 <= n * m)
			{
				x = fen[i];
				fen[i] = fen[i + 1];
				fen[i + 1] = x;
			}
	}
	for(int i = 1; i <= n * m; i++)
	{
		if(fen[i] < fen[i + 1] && i + 1 <= n * m)
		{
			x = fen[i];
			fen[i] = fen[i + 1];
			fen[i + 1] = x;
		}
		if(fen[i] == w)
		{
			r = i;
		}
	}
	hang = r % n;
	lie = r % m;
	if(lie % 2 == 1)
	{
		ans1 = n - hang + 1;
	}
	else
	{
		if(hang == 0)
		{
			ans1 = n;
		}
		else
		{
			ans1 = hang + 1;
		}
	}
	if(r % n == 0)
	{
		ans2 = r / n;
	}
	else
	{
		ans2 = r / n + 1;
	}
	cout << ans2 << ' ' << ans1;
	return 0;
}
