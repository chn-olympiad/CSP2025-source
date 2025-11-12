#include <bits/stdc++.h>
using namespace std;
int T, n, a[100005], b[100005], c[100005], sum;
int main ()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdin);
	cin >> T;
	while (T--)
	{
		cin >> n;
		sum=0;
		for (int i=1; i<=n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		sort (a+1, a+n+1);
		for (int j=n; j>=n/2+1; j--)
		{
			sum+=a[j];
		}
		cout << sum << endl;
	}
	return 0;
}
 
