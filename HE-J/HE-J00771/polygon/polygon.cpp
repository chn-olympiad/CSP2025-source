#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int modi = 998244353;
int n, l[5001];
ll qpow(ll a, ll b)
{
	while(b--)
		a = a * a % modi;
	return a;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> l[i];
	cout << (qpow(2, n) % modi - n * (n + 1) / 2 - 1) % modi;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
