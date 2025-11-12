#include <bits/stdc++.h>

using namespace std;

int n,m,c[505];
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;

	for(int i = 1;i<=n;++i)
		cin >> c[i];

	cout << [n*(n+1)/2] % 998244353;

	return 0;
}
