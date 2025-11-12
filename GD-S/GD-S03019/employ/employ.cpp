#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans;
int n,m,c[1010];
string s;
bool f=1;
int f2;
const long long mod=998244353;

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];if(c[i]==0)f2++;
	}
	n-=f2;
	if(n<m)
	{
		cout<<0;return 0;
	}
	if(f==1)
	{
		
		ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		cout<<ans;
	}
	
	return 0;
}
