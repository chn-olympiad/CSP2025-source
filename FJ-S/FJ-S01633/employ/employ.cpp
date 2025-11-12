#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
char a[506];
int b[506];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n, m, ans=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	cin >> a[i];
	for(int i=1;i<=n;i++)
	cin >> b[i];
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout << ans;
	return 0;
}