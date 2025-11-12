#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],vis=1,cnt,mod=998244353,ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)	cin>>c[i];
	for(int i=0;i<n;i++)
	{
		if(s[i]==0)
			vis=0;
	}
	if(vis)
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i]<1)
				cnt++;
		}
		cnt=n-cnt;
		if(cnt<m)
		{
			cout<<0;
			return 0;
		}
		else
		{
			for(int i=1;i<=n;i++)
				ans=(ans*i)%mod;
		}
	}
	cout<<ans;
	return 0;	
} 
