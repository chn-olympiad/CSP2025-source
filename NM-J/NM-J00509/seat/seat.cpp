#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[110];

bool cmp(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;

	int len = n * m;
	for (int i = 1; i <= len; i++)
		cin >> a[i];

	int R = a[1];
	sort(a + 1, a + len + 1, cmp);

	int num;
	for (int i = 1; i <= len; i++)
		if (a[i] == R)
			num = i;

	int x = (num % n ? num / n + 1 : num / n);

	int y;
	if (x & 1)
	{
		y = (num % n ? num % n : n);
	} else
	{
		y = (num % n ? n - num % n + 1 : 1);
	}

	cout << x << ' ' << y << endl;

	return 0;
}
