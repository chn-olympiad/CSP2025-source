#include <iostream>
#include <algorithm>
using namespace std;

int n, a[5005], p[5005];
const int MOD = 998244353;
int cnt;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n < 3)
		cout << 0;
	if (n == 3)
		cout << (a[1] + a[2] > a[3]);
	
	
	return 0; 
}
