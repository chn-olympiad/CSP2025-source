#include<iostream>
using namespace std;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, k;
	cin >>n >> m >> k;
	cout << k % 998 % 244 % 353 << endl;
	return 0;
}
