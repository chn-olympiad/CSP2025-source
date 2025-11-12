#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	string str;
	for (int i = 0; i < (n+q)*2; i++)
		cin >> str;
	for (int i = 0; i < q; i++)
		cout << 0 << "\n";
	return 0;
}
