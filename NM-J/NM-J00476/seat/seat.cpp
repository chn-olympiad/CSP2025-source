#include <bits/stdc++.h>
#define ls cur << 1
#define rs cur << 1 | 1
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
typedef long long ll;
using namespace std;
const int N = 1e6 + 10;
int a[105];
int main() // ÎÄ¼ş¶ÁĞ´ 
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; cin >> n >> m;
	rep(i, 1, n*m) cin >> a[i];
	int x = a[1];
	sort(a + 1, a + 1 + n*m); reverse(a + 1, a + 1 + n*m);
	int id;
	rep(i, 1, n*m) if(a[i] == x) id = i;
	int lie = ceil(1.0*id / n);
	int hang;
	if(lie & 1) hang = id - (lie-1) * n;
	else hang = n - (id - (lie-1) * n) + 1;
	cout << lie << ' ' << hang;
	return 0;
} 
