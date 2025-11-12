#include <iostream>
using namespace std;
int n, k;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	if (k == 0){
	cout << 0;}
	else
	{
		int x, xx, ans = 0;
		cin >> xx;
		for (int i = 1; i <= n - 1; i++)
		{
			cin >> x;
			swap(x, xx);
			if (x == 1)
			{
				ans++;
				cin >> x;
				swap(x, xx);
				i++;
			}
		}
		cout << ans << endl;}
	return 0;
}
