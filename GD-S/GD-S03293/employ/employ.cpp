#include <iostream>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans = 1;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1;i <= n;i++)
	{
		ans = (ans * i) % 998244353;
	}
	cout << ans << endl;
	return 0;
}
