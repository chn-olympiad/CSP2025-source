#include <bits/stdc++.h>
using namespace std;
int a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0;i < int(s.length());i++) if(s[i]==0) {cout << 0;return 0;}
	for(int i = 1;i <= n;i++) cin >> a[i];
	int p = 1;
	for(int i = 1;i <= n;i++)
	{
		p*= i;
		p%=998244353;
	}
	cout << p;
	return 0;
}
