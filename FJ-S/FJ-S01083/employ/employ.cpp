#include<bits/stdc++.h>
using namespace std;
int n, q;
const int N = 2e5 + 5;
string s1[N], s2[N], t1[N], t2[N];
int ans;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> t1[i] >> t2[i];
	}
	
	cout << ans % 998244353 << endl;
	return 0;
}
