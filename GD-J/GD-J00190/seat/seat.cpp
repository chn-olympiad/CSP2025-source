#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n , m , a[N];
bool cmp (int x , int y) {return x > y;}
signed main ()
{
	freopen ("seat.in" , "r" , stdin);
	freopen ("seat.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	cin >> n >> m;
	m *= n;
	for (int i = 1;i <= m;i ++) cin >> a[i];
	int sc = a[1];
	sort (a + 1 , a + m + 1 , cmp);
	int p = 1;
	while (a[p] != sc) p ++;
	p --;
	int x = p / n + 1;
	int y = p % n + 1;
	if (x % 2 == 0) y = n - y + 1;
	cout << x << ' ' << y;
	return 0;
}
