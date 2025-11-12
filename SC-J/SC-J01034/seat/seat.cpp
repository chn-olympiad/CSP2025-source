#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;

int n, m, f = 1;
int x = 1, y = 1; 
struct node
{
	int v, id;
};
node a[maxn + 5];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i)
		cin >> a[i].v, a[i].id = i;
	sort(a + 1, a + n * m + 1, [](node o, node p) {
		return o.v > p.v;
	});
	for(int i = 1; i <= n * m; ++i)
	{
		if(a[i].id == 1)
		{
			cout << y << ' ' << x << endl;
			return 0;
		}
		if(x == n && f == 1)
			++y, f = 0;
		else if(x == 1 && f == 0)
			++y, f = 1;
		else
		{
			if(f) ++x;
			else --x;
		}
	}
	return 0;
}