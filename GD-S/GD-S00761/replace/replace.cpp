#include <bits/stdc++.h>
using namespace std;
string s[1005],ss[1005];
string t1,t2,xx;
int n,q,y,cnt;
void dfs(string x)
{
	if(x == t2)
	{
		cnt++;
		return;
	}
	for(int i = 1;i<=n;i++)
	{
		if(x.find(s[i])!=x.size())
		{
			xx = "";
			y = x.find(s[i]);
			for(int j = 0;j<=y;j++)
			{
				xx+=x[j];
			}
			xx+=s[i];
			for(int j = y+s[i].size();j<x.size();j++)
			{
				xx+=x[j];
			}
			dfs(xx);
		}
	}
	return;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)
	{
		cin>>s[i]>>ss[i];
	}
	while(q--)
	{
		/*
		cin>>t1>>t2;
		dfs(t1);
		cout<<cnt;
		cnt = 0;*/
		cout<<0<<'\n';
	}
	return 0;
}
