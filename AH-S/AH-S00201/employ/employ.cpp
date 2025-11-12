#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int c[505];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool f=1;
	for(int i=1;i<=n;i++)  cin>>c[i];
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			f=0;
			break;
		}
	}
	if(m==n)
	{
		int t=1;
		for(int i=1;i<=n;i++)  if(c[i]==0)  f=0;
		for(int i=1;i<=n;i++) t*=i,t%=mod;
		if(f)  cout<<t;
		else  cout<<0;
		return 0;
	}
	if(m==1)
	{
		int k=0;
		for(;k<n;k++)
		{
			if(s[k]=='1')  break;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)  if(c[i]>=k)  cnt++;
		int t=1;
		for(int i=1;i<=n-1;i++)  t*=i,t%=mod;
		cout<<cnt*t%mod;
		return 0;
	}
	if(f)
	{
		int t=1,cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]!=0)  cnt++;
		}
		for(int i=1;i<=cnt;i++)  t*=i,t%=mod;
		cout<<t%mod;
	}
	return 0;
}
