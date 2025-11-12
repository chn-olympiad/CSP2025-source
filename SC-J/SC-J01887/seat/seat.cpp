#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
bool custom_Cmp(int x, int y)
{
	return x > y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int sum = n * m;
	for (int i = 0; i < sum; i ++)
	{
		cin >> a[i];
	}
	int sr = 0, pos = 0;
	sr = a[0];
	sort (a, a + sum, custom_Cmp);
	for (int i = 0; i < sum; i ++)
	{
		//cout << a[i] << " ";
		if (a[i] == sr)
		{
			pos = i + 1;
		}
	}
	//cout << endl;
	//n 行 m 列
	int row = ceil(pos * 1.0 / n);//列
	int line = 0;//行
	if (pos % n == 0) line = (row & 1) ? n : 1;
	else {
		line = (row & 1) ? (pos % n) : (n - pos % n + 1);
	}
	//cout << pos << " ";
	cout << row << " " << line << endl;
	return 0;
}