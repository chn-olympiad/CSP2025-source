#include<bits/stdc++.h>
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
int n,k,ans,a[500006],s[500006];
set<int>se;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]^a[i];
	}
	se.insert(0);
	for(int i=1;i<=n;i++)
	{
		if(se.find(s[i]^k)!=se.end())
		{
			ans++;
			se=set<int>();
			se.insert(s[i]);
		}
		else
		{
			se.insert(s[i]);
		}
	}
	cout<<ans;
	return 0;
}