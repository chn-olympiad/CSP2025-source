#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=501;
bool s[N];
int a[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==n)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
			if(!s[i]||!a[i])
			{
				cout<<0;
				return 0;
			}
		}
		cout<<ans;
	}

	return 0;
}
