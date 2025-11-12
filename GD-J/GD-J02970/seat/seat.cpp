#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define x first
#define y second

const int N = 15;

int n, m;
int a[N * N];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++ ) cin >> a[i];
	
	int tmp = a[1];
	sort(a + 1, a + n * m + 1, [](int x, int y){
		return x > y;
	});
	
	int pos;
	for (pos = 1; pos <= n * m; pos ++ )
		if (a[pos] == tmp)
			break;
	pos -- ;
	
	int x = 1, y = 1;
	int t = 1;
	while (pos -- )
	{
		if (1 <= x + t && x + t <= n) x += t;
		else
		{
			y ++ ;
			t = -t; 
		}
	}
	
	cout << y << ' ' << x << '\n';

	return 0;
}

