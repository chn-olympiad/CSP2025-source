#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 10;

int n, m;
int a[N];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++ )
		cin >> a[i];
	int now = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int pos = 0;
	for(int i = 1; i <= n * m; i ++ )
		if(a[i] == now)	
		{
			pos = i;
			break;
		}
	int row = 0, col = 0;
	if(pos % n != 0)
		col = pos / n + 1;
	else
		col = pos / n;
	if(col % 2 == 0)
		row = (pos % n == 0 ? 1 : n - pos % n + 1);
	else
		row = (pos % n == 0 ? n : pos % n);
	cout << col << ' ' << row;
	return 0;
}
