#include <iostream>
using namespace std;
const int MOD = 998244353;
int n,a[5005],yu;
int main()
{
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= i-1;j++)
		{
			yu += a[j];
		}
		if (yu <= a[i])
		{
			yu -= yu;
			yu += a[i];
			break;
		}
	}
	cout << yu*yu%MOD;
	return 0;
}
