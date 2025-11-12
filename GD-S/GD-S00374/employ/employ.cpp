#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 998244353;
int main()
{
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[510],ans = 1;
	string s;
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)
		cin >> c[i];
	for(int i = 1;i <= n;i++)
		ans = 1ll * ans * i % mod;
	cout << ans;
	return 0;
}
