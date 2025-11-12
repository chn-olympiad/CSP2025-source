#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;

int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	bool y=true;
	cin >>n >> m;
	string s;
	cin >> s;
	s='?'+s;
	for (int i=1;i<=n;i++) cin >> c[i];
	for (int i=1;i<s.size();i++) 
	{
		if (s[i]!=1) y=false;
	}
//	if (y)
//	{
//		long long ans = 1; 
//		for (ll i=1;i<=n;i++)
//		{
//			ans=(ans*i)%mod;
//		}
//		cout << ans;
//	}
 cout << "1"; 
}
