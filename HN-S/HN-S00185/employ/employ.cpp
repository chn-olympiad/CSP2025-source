#include<bits/stdc++.h>
using namespace std;
int n, m, a[1010], cnt = 1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		cnt = cnt * i % 998244353;
	}
	cout << cnt << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

