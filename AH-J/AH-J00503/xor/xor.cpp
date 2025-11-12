#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n, m;
int x;

void count()
{
	for(int i = 1; i <= n; i++)
		if(a[i] == 1)
			x++;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	count();
	if(m == 1)
		cout << max(x, (n - x) / 2);
	else
		cout << max(n - x, x / 2);
	return 0;
}
