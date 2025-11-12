#include<bits/stdc++.h>
using namespace std;
//#define int long long

const int N = 105;

int a[N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	int x = a[1];
	sort(a + 1, a + n * m + 1);
	reverse(a + 1, a + n * m + 1);
	int p;
	for(int i = 1; i <= n * m; i++)
		if(a[i] == x) p = i;
	int c = (p - 1) / n + 1;
	int r = (p - 1) % n + 1;
	if(c % 2 == 0) r = n - r + 1;
	cout << c << ' ' << r;
	
	return 0;
}


