#include<bits/stdc++.h>
#define pii pair<int,int>
#define allof(o) (o).begin(),(o).end()
#define lowbit(x) ((x)&(-(x)))
using namespace std;
map<string,vector<string> > mp;
string s1[200005];
string s2[200005];
int n,m;

bool check(const string &s,int p,const string &x)
{
	for(int i=0;i<x.length();i++)
		if(s[p+i]!=x[i])return 0;
	return 1;
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		mp[s1[i]].push_back(s2[i]);
	}
	while(m--)
	{
		string s,t;
		cin>>s>>t;
		int cnt=0;
		for(auto p:mp)
		{
			string x=p.first;
			vector<int> v;
			for(int i=0;i+x.length()-1<s.size();i++)
				if(check(s,i,x))
				{
					string qz=s.substr(0,i);
					string hz;
					if(i+x.length()!=s.size())
						hz=s.substr(i+x.length());
					for(auto y:p.second)
					{
						string tmp=qz+y+hz;
						if(tmp==t)cnt++;
					}
				}
		}
		cout<<cnt<<'\n';
// cerr<<"# "<<m<<'\n';
	}
	return 0;
}