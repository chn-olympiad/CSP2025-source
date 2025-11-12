#include <bits/stdc++.h>
using namespace std;
int n,m,mo=998244353,sd;
string s;
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>sd;
	for(int i=n;i>=1;i--)
	{
		ans*=i;
		ans%=mo;
	}
	cout<<ans<<'\n';
	return 0;
}