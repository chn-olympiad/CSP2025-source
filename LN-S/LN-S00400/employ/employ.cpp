#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin >> n;
	int ans =1;
	for (int i = 1; i <= n; i ++ )
	{
		ans = (1ll*ans*i)%998244353;
	}
	cout << ans;
}
