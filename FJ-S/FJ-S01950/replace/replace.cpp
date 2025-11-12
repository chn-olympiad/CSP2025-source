#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

string s[200005],t[200005];
int n;

long long dfs(string a,string b)
{
	if(a==b) 
	{
		return 1;
	}

	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		int pos=a.find(s[i]);
		while(pos!=-1)
		{
			if(a.substr(0,pos)+t[i]+a.substr(pos+s[i].size())==b) ans++;
			pos=a.find(s[i],pos+1);
		}
	}
	return ans;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i]>>t[i];
	}
	for(int i=1;i<=q;++i)
	{
		string a,b;
		cin>>a>>b;
		cout<<dfs(a,b)<<"\n";
	}
	return 0;
}
