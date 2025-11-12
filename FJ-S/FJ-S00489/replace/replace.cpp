#include<bits/stdc++.h>
using namespace std;
string t1,t2,s1,s2;
map<pair<int,int>,int> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++)
		{
			if(s1[j]=='b')
			{
				x=j;
			}
			if(s2[j]=='b')
			{
				y=j;
			}
		}
		mp[{x,y}]++;
	}
	for(int i=1;i<=q;i++)
	{
		int x,y,ans=0;
		cin>>t1>>t2;
		for(int j=0;j<t1.size();j++)
		{
			if(t1[j]=='b')
			{
				x=j;
			}
			if(t2[j]=='b')
			{
				y=j;
			}
		}
		for(int i=0;i<=x;i++)
		{
			ans+=mp[{i,i+y-x}];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
