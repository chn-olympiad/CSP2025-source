#include <iostream>
#include <algorithm>
using namespace std;
const int N = 20;

int a[N * N];

bool cmp(int a, int b)
{ return a > b; }

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k, x, id;
	cin >> n >> m >> a[1];
	k = n * m;
	x = a[1];
	for (int i = 2; i <= k; i++) cin >> a[i];
	sort(a + 1, a + k + 1, cmp);
	for (id = 1; id <= k && a[id] != x; id++);
	int ansc = (id - 1) / n + 1, ansr;
	if (ansc % 2 == 1) ansr = (id - 1) % n + 1;
	else ansr = n - (id - 1) % n;
	cout << ansc << ' ' << ansr << '\n';
	return 0;
}

