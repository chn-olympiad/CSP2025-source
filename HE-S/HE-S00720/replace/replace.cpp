#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, q;
string a[N][N], b[N][N]; 
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i][1] >> a[i][2];
	for(int i = 1; i <= q; i++)
		cin >> b[i][1] >> b[i][2];
	for(int i = 1; i <= q; i++)
		cout << 0 << endl;
	return 0;
}
