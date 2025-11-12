#include <bits/stdc++.h>
//#include <windows.h>
using namespace std;
const int N = 5001;
int n, cnt;
int a[N];
void dfs(int i, int s, int ch)
{
//	printf("i = %d s = %d ch = %d\na = ", i, s, ch);
//	for (int x = 1; x <= n; x++)
//		cout << a[x] << " ";
//	cout << endl;
//	cout << "cnt = " << cnt << endl;
//	system("pause");
	if (ch == 0)
	{
		if (s > a[i - 1] * 2)
			cnt = (cnt + 1) % 998244353;
		return;
	}
	if (i > n)
		return;
//	cout << endl << "选第" << i << "根小木棍" << endl;
	dfs(i + 1, s + a[i], ch - 1);
//	cout << endl << "不选第" << i << "根小木棍" << endl;
		dfs(i + 1, s, ch);
	}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int len = 3; len <= n; len++)
		dfs(1, 0, len);
	cout << cnt << endl;
	return 0;
}
