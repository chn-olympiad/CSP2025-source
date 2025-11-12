#include <bits/stdc++.h>
#define int long long
int a[520],vis[520];
const int mod=998244353;
using namespace std;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int len=s.size();
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n)
	{
		for(int i=0;i<len;i++)
		{
			if(s[i]!='1') 
			{
				cout<<0;
				return 0;
			}
			
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++) ans=(ans*i)%mod;
	cout<<ans;
}