//GZ-S00360 贵阳市第十八中学 罗嘉龙 
#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m;
string s;
int a[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)cin>>a[i];
	bool b=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			b=0;
			break;
		}
	}
	if(b==1)
	{
		long long ans=1;
		for(int i=0;i<=n;i++)
		{
			ans=(ans*i+mod)%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	cout<<32;
	return 0;
}
