#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
string a[200007],b[200007];
bool z(string s1,string s2)
{
	if(s1.size()!=s2.size())
	{
		return 0;
	}
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s2[i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++)
	{
		ans=0;
		string x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++)
		{
			int l=a[j].size();
			for(int k=0;k<x.size()-l+1;k++)
			{
				string tmp=x.substr(k,l);
				if(z(a[j],tmp)==1)
				{
					tmp=x.substr(0,k)+b[j]+x.substr(k+l);
					if(z(y,tmp)==1)
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
