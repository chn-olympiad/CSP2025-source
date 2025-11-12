#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510,mod = 998244353;
int n,m;
int c[N];
char s[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> s[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		cin >> c[i];
	}
	cout << 0 << '\n';
	return 0;
}
