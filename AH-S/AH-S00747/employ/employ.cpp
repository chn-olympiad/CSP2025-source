#include<bits/stdc++.h>
using namespace std;
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(!c[i])
			cnt++;
	}
	if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
	}
	if(n-cnt>=m)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
}
