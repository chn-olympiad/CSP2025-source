#include <bits/stdc++.h>
#define ll long long
using namespace std;
int stick[5010];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n; cin >> n; int sum = 0;
	int maxx = 0;
	for(int i=1; i<=n; i++)
	{
		cin >> stick[i], sum += stick[i];
		maxx = max(maxx, stick[i]);
	}
	if(n == 3)
	{
		if(sum > 2 * maxx) cout << 1 << endl;
		else cout << 0 << endl;
	}
	if(sum == n && maxx == 1) cout << n - 2 << endl;
	return 0;
}