#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int mod=1e9+7,base=131;
int n,Q,cnt=0,ch[5000005][28],sum[5000005],fa[5000005];
string s1,s2;
vector<int> edge[5000005];
map<pair<int,int>,int> mp;
int get(char c)
{
	return (c=='?'?26:c-'a');
}
void insert(int x,string s)
{
	int u=x;
	for(int i=0;i<(int)s.size();i++)
	{
		if(!ch[u][get(s[i])])
		{
			cnt++;
			ch[u][get(s[i])]=cnt;
		}
		u=ch[u][get(s[i])];
	}
	sum[u]++;
}
void build(int u)
{
	queue<int> q;
	for(int i=0;i<=26;i++)
	{
		if(ch[u][i])
		{
			fa[ch[u][i]]=u;
			edge[u].push_back(ch[u][i]);
			q.push(ch[u][i]);
		}
		else
		{
			ch[u][i]=u;
		}
	}
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		for(int i=0;i<=26;i++)
		{
			if(ch[v][i])
			{
				fa[ch[v][i]]=v;
				edge[v].push_back(ch[v][i]);
				q.push(ch[v][i]);
			}
			else
			{
				ch[v][i]=v;
			}
		}
	}
}
int ask(int v,string s)
{
	int u=v,res=0;
	for(int i=0;i<(int)s.size();i++)
	{
		u=ch[u][get(s[i])];
		res+=sum[u];
	}	
	return res;
}
void dfs(int u)
{
	for(int i=0;i<(int)edge[u].size();i++)
	{
		int v=edge[u][i];
		sum[v]+=sum[u];
		dfs(v);
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		int l=-1,r=-1;
		for(int j=0;j<(int)s1.size();j++)
		{
			if(s1[j]!=s2[j])
			{
				r=j;
				if(l==-1)
				{
					l=j;
				}
			}
		}
		if(l==-1)
		{
			continue;
		}
		string s="";
		for(int i=0;i<=l-1;i++)
		{
			s+=s1[i];
		}
		s+='?';
		for(int i=r+1;i<(int)s1.size();i++)
		{
			s+=s1[i];
		}
		int x=0,y=0;
		for(int i=l;i<=r;i++)
		{
			x=(1ll*x*base%mod+s1[i]-'a')%mod;
			y=(1ll*y*base%mod+s2[i]-'a')%mod;
		}
		if(!mp.count({x,y}))
		{
			cnt++;
			mp[{x,y}]=cnt;
		}
		insert(mp[{x,y}],s);
	} 
	for(auto i:mp)
	{
		build(i.second);	
	}
	for(auto i:mp)
	{
		dfs(i.second);	
	}
	while(Q--)
	{
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<0<<endl;
			continue;
		}
		int l=-1,r=-1;
		for(int j=0;j<(int)s1.size();j++)
		{
			if(s1[j]!=s2[j])
			{
				r=j;
				if(l==-1)
				{
					l=j;
				}
			}
		}
		string s="";
		for(int i=0;i<=l-1;i++)
		{
			s+=s1[i];
		}
		s+='?';
		for(int i=r+1;i<(int)s1.size();i++)
		{
			s+=s1[i];
		}
		int x=0,y=0;
		for(int i=l;i<=r;i++)
		{
			x=(1ll*x*base%mod+s1[i]-'a')%mod;
			y=(1ll*y*base%mod+s2[i]-'a')%mod;
		}
		if(!mp.count({x,y}))
		{
			cout<<0<<endl;
			continue;
		}
		cout<<ask(mp[{x,y}],s)<<endl;
	}
	return 0;
}
