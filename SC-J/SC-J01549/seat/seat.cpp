#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int goal = a[1], id = 0;
	sort(a + 1, a + n * m + 1, greater<int>());
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == goal) id = i;
	}
	int Mod = id % n, s = id / n;
	if(s & 1)
	{
		cout << s + (Mod != 0) << ' ' << (Mod == 0 ? n : n - Mod + 1) << '\n';
	}
	else
	{
		cout << s + (Mod != 0) << ' ' << (Mod == 0 ? 1 : Mod) << '\n';
	}

	return 0;
}