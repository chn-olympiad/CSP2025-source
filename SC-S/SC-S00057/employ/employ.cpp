#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mod=998244353,c[505],vis[505],a[505],ans,v;
string s;
void go(int i)
{
	if(i==n+1)
	{
		int cnt=0,sum=0;
		for(int j=0;j<n;j++)
		{
			if(cnt>=c[a[j+1]]) cnt++;
			else if(s[j]=='0') cnt++;
			else sum++;
		}
		if(sum>=m) ans=(ans+1)%mod;
		return;
	}
	for(int j=1;j<=n;j++)
	{
		if(!vis[j])
		{
			vis[j]=1;a[i]=j;go(i+1);a[i]=0;vis[j]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];if(!c[i]) v++;
	}
	if(n<100) go(1);
	cout<<ans;
	return 0;
}