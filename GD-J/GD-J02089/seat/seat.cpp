#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int num;

int a[1919810];

signed main()
{
	ifstream cin("seat.in");
	ofstream cout("seat.out");
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	num = n * m;
	int cnt = 1;
	
	for (int i = 1; i <= num; ++i)
	{
		cin >> a[i];
		if (a[i] > a[1])
		{
			cnt++;
		}
	}
	
	if (cnt == 1)
	{
		cout << "1 1\n";
		return 0;
	}
	
	int x = (long long)ceill((long double)cnt / n);
	
	cout << x << ' ';
	
	if (x & 1)
	{
		cout << cnt - (x - 1) * n << '\n';
	}
	else
	{
		cout << n - (cnt - (x - 1) * n) + 1 << '\n';
	}
}
