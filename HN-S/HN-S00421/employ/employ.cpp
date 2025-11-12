#include<bits/stdc++.h>
using namespace std;
int c[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int x=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			x++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(x==n)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
		}
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
