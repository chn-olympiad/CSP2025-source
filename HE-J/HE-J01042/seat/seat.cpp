#include<bits/stdc++.h>
using namespace std;

const int N  = 1e2 + 12;
int n, m, a[N], cur, c, r;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
		if(a[i] > a[1]) cur++;
	}
	c = cur / n + 1;
	r = cur % n + 1;
	if(!(c & 1)) r = n - r + 1;
	cout << c << " " << r << endl;
	return 0;
}
