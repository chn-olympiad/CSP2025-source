#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int f[555];
	for(int i = 1;i<=n;i++)
	{
		cin>>f[i];
	}
	long long ans = 1;
	for(int i = 1;i<=n;i++)
	{
		ans = (ans % mod * i % mod) % mod;
	}
	cout<<ans<<endl;
	return 0;
}
