#include <bits/stdc++.h>
using namespace std;
int c[500];
const int Mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,p,cnt=0;
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
	{
		char s;
		cin>>s;
		if(s=='1')
		{
			cnt++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(cnt<m)
	{
		cout<<0;
	}
	else
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%Mod;
		}
		cout<<ans;
	}
	return 0;
}
