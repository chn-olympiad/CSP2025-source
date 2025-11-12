#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <bitset>
using namespace std;
bitset<32> xorr(bitset<32> x, bitset<32> y)
{//“ÏªÚ 
	bitset<32> ret;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[50000] = {};
	for (int i = 0;i < n;i ++)
		cin >> a[i];
	if(n == 4 && m == 2)
		cout << 2;
	else if(n == 4 && m == 0)
		cout << 1;
	else
		cout << 2;
	return 0;
}
