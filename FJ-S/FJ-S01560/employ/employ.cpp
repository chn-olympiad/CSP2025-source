#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
//int ksc(int x,int y)
//{
//	int ans=1;
//	while(y)
//	{
//		if(y&1)ans=ans*x%mod;
//		x=x*x%mod;
//	}
//	return ans;
//}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int tot=n;
	string s;
	cin>>s;
	int c[n+1];
	for(int i=1;i<=n;i++)cin>>c[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]<=cnt)cnt++;
	}
	cout<<cnt<<endl;
	if(n-cnt<m)
	{
		cout<<0<<endl;
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n-cnt;i++)
	{
		ans=(long long)ans*i%mod;
	}
	cout<<ans<<endl;
	return 0;
}

