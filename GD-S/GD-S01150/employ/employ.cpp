#include<bits/stdc++.h>
using namespace std;
int c[505],a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int peo=0;
	for(int i=0;i<s.size();i++)
	{
		a[i]=s[i]-48;
		if(a[i]==0)
		{
			ans-=n/s.size();
			peo+=n/s.size();
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]<=peo)
			{
				ans--;
			}
		}
	}
	ans=ans%998%244%353;
	cout<<ans<<endl;
	return 0;
 } 
