#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N];
bool cmp(int x, int y) { return x > y;}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int sc = a[1], id;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if (a[i] == sc)
			id = i;
	

//	cout << id << '\n';
	//计算列数 
	int c = (id % n) ? id / n + 1 : id / n;
	cout << c << ' ';
	//计算行数 
	
	int r = id % n;
	if (!r) r = n;
	if (c % 2)
	{
		//奇数列从上向下
		cout << r << '\n';
	}
	else
	{
		//偶数列从下向上
		r = n - r + 1;
		cout << r << '\n';
	}
	return 0;
}
