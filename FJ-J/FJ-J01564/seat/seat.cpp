#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n; cin >> m >> n;
	int a[105] = {}; for (int i = 0; i < m * n; ++i) cin >> a[i];
	int R = a[0];
	sort(a, a + m * n, compare);
	//for (int i = 0; i < m * n; ++i) cout << a[i] << ' ';
	int l = 0, r = m * n, mid, point = -1;
	while (l <= r)
	{
		mid = (l+r) / 2;
		if (a[mid] > R) l = mid + 1;
		else if (a[mid] < R) r = mid;
		else {
			point = mid;
			break;
		}
	}
//	if (point == -1) 
//	{
//		cout << endl << l << ' ' << r;
//	}
	//cout << point;
	cout << point / n + 1 << ' ' << (point / n % 2 ? n - point % n : point % n + 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
