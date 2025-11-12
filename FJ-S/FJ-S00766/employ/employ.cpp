#include<iostream>
using namespace std;
char s[505];
int c[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m >> s+1;
	for(int i=1;i<=n;i++)
		cin >> c[i];
	
	long long ans = 1;
	for(int i=1;i<=n;i++)
		ans = ans * i % 998244353;
	for(int i=1;i<=n;i++)
		if (s[i] == '0')
			ans = 0;
	
	cout << ans;
	
	return 0;
}
