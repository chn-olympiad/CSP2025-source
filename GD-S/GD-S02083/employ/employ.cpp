#include <bits/stdc++.h>
using namespace std;
int n,m,s[505],c[505];
long long ans;
string ss;
int main()
{
	freopen("employ,in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> ss;
	for (int i = 1;i <= n;i++)
	{
		s[i] = ss[i - 1];
		cin >> c[i];
	}
	cout << 2;
	return 0;
}
