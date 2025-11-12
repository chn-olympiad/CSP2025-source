#include <bits/stdc++.h>
using namespace std;
int n,q;
set<string> s;
map<string,string> mp;
int fin (string sz,string fi)
{
	for(int i=0;i+fi.size()-1<sz.size();i++)
		if(sz.substr(i,fi.size())==fi) return i;
	return -1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string u,v;
		cin>>u>>v;
		s.insert(u);
		mp[u]=v;
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		string u,v,g;
		cin>>u>>v;
		set<string>::iterator it;
		for(it=s.begin();it!=s.end();it++)
		{
			int y=fin(u,*it);
			if(y==-1) continue;
			else
			{
				string g=u;
				g.replace(y,(*it).size(),mp[*it]);
				if(g==v) ans++;
			}
		} 
		printf("%d\n",ans);
	}
	return 0;
}
