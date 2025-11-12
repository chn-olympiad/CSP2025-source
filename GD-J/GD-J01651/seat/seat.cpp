#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//typedef long long LL;
const int MAXN = 105;
int a[MAXN];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int N = n * m;
	
	for (int i = 1; i <= N; i++) cin >> a[i];
	
	int tag = a[1];
	
	sort(a + 1, a + N + 1, greater<int>());
	
	int pos = 0;
	for (int i = 1; i <= N; i++)
	{
		if (tag == a[i])
		{
			pos = i;
			break;
		}
	}
	
//	cout << pos << endl;
	
	int c = ceil(1.0 * pos / n);
	int tmp = (pos % n ? pos % n : n);
	int r = (c % 2 == 1 ? tmp : n - tmp + 1);
	
	cout << c << ' ' << r << endl;
	
	return 0;
}
