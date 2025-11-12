#include <bits/stdc++.h>
using namespace std;

const int N = 5010,MOD=998244353;
int n,ans=0;
int a[N];

long long func(int a)
{
	if(a==1)    return 1;
	return a*func(a-1);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++)    cin >> a[i];
	for(int i=3; i<=n; i++)
	{
		ans += func(n)/func(i)%MOD;
	}
	ans = ans%MOD;
	cout << ans << endl;
	return 0;
}
