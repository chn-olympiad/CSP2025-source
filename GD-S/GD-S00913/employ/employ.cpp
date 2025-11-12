#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
string s;
int c[501];
bool ok=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for (int i=0;i<s.length();i++)
	{
		if (s[i]!='1') ok=1;
	}
	if (!ok)
	{
		long long ans=1;
		for (int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if (m==n) cout<<0;
	return 0;
}
//*** have no egg
