#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >>n>>m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
	}
	long long ans=1;
	for(int i = 1; i <= n;++i)
	{
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
