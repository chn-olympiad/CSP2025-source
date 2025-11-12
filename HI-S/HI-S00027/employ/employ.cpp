#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,m,s,c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	cout << s/m%MOD;
	return 0;
}

