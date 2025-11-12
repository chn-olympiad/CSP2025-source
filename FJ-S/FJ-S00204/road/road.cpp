#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n;
	cin >> n;
	int k = n << 25;
	cout << k % 998244353;
}
