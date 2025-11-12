#include<bits/stdc++.h>
#define ls(p) p<<1
#define rs(p) p<<1|1
using namespace std;
const int maxn=5e5+5;
int n,q,ans[maxn],tree[maxn*4];
vector<int>v1[maxn],v2[maxn];
vector<pair<int,int>>p[maxn];
struct node{
	int a,b,id;
}t[maxn];
struct Node{
	node a,b;
}qu[maxn];
void updata(int p,int pl,int pr,int l,int r,int d)
{
//	cout<<l<<" "<<r<<"\n";
	if(l<=pl&&r>=pr)
	{
		tree[p]+=d;
		return;
	}
	int mid=(pl+pr)>>1;
	if(l<=mid)
		updata(ls(p),pl,mid,l,r,d);
	if(r>mid)
		updata(rs(p),mid+1,pr,l,r,d);
}
int query1(int p,int l,int r,int x)
{
	if(l==r)
	{
		return tree[p];
	}
	int ans=tree[p];
	int mid=(l+r)>>1;
	if(x<=mid)
		return ans+query1(ls(p),l,mid,x);
	else
		return ans+query1(rs(p),mid+1,r,x);
}
struct ac{
	int tree[maxn][26],cnt,dfn[maxn],cnt1=0,siz[maxn],fail[maxn];
	node t1[maxn];
	vector<int>ed[maxn];
	vector<int>vt[maxn];
	void init()
	{
		memset(tree,0,sizeof(tree));
		cnt=0;
		cnt1=0;
	}
	void insert(string s,int id)
	{
		int cur=0;
		for(int i=0;i<s.size();i++)
		{
			if(!tree[cur][s[i]-'a'])
			{
				tree[cur][s[i]-'a']=++cnt;
			
				}
			cur=tree[cur][s[i]-'a'];
		}
		ed[cur].push_back(id);
	}
	void build()
	{
		queue<int>q;
		for(int i=0;i<26;i++)
			if(tree[0][i])
			{
			
				fail[tree[0][i]]=0;	
			
				q.push(i);
			}
		while(!q.empty())
		{
			int tmp=q.front();
			q.pop();
			for(int i=0;i<26;i++)
			{
				if(tree[tmp][i])
				{
					fail[tree[tmp][i]]=tree[fail[tmp]][i];
				}else
					tree[tmp][i]=tree[fail[tmp]][i];
			}
		}
		for(int i=1;i<=cnt;i++)
		{
			vt[fail[i]].push_back(i);
		}
		for(int i=0;i<26;i++)
			if(tree[0][i])
			{
			
				cout<<fail[tree[0][i]]<<"\n";
			}
	}
	void dfs(int x)
	{
		dfn[x]=++cnt1;
		siz[x]=1;
		for(int v:vt[x])
		{if(v)
		{
		
			dfs(v);
			siz[x]+=siz[v];
		}
		}
		for(int v:ed[x])
			t1[v]={dfn[x],dfn[x]+siz[x]-1,0};
	}
}s1,s2;
void query(string t1,string t2,int id)
{
	int cur1=0,cur2=0;
	for(int i=0;i<t1.size();i++)
	{
		cur1=s1.tree[cur1][t1[i]-'a'];
		cur2=s2.tree[cur2][t2[i]-'a'];
//		cout<<cur1<<" "<<cur2<<"\n";
		p[s1.dfn[cur1]].push_back({s2.dfn[cur2],id});
	}
}
void solve1()
{
	s1.init();
	s2.init();
	for(int i=1;i<=n;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		s1.insert(t1,i);
		s2.insert(t2,i);
	}
	s1.build();
	s2.build();
	s1.dfs(0);
	s2.dfs(0);
	for(int i=1;i<=n;i++)
	{
		qu[i]={s1.t1[i],s2.t1[i]};
		v1[s1.t1[i].a].push_back(i);
		v2[s1.t1[i].b].push_back(i);
	}
	for(int i=0;i<=s1.cnt;i++)
	{
		cout<<i<<" "<<s1.dfn[i]<<" "<<s1.fail[i]<<" 1919810\n";
		for(int j=0;j<26;j++)
		{
			if(s1.tree[i][j])
			{
				cout<<char(j+'a')<<" "<<s1.tree[i][j]<<"\n";
			}
		}
	}
//	cout<<114514<<"\n";
	for(int i=1;i<=q;i++)
	{
//		cout<<1919810<<"\n";
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			ans[i]=0;
			continue;
		}
		query(t1,t2,i);
	}
//	cout<<114514<<"\n";
//	cout<<s1.cnt<<"\n";
	for(int i=1;i<=s1.cnt;i++)
	{
//		cout<<i<<"\n";
		for(int u:v1[i])
		{
//			cout<<u<<"\n";
			updata(1,1,maxn-5,s2.t1[u].a,s2.t1[u].b,1);
		}
//		cout<<i<<"\n";
		for(auto v:p[i])
		{
			ans[v.second]+=query1(1,1,maxn-5,v.first);
		}
			for(int u:v2[i])
		{
				updata(1,1,maxn-5,s2.t1[u].a,s2.t1[u].b,-1);
		}
//		cout<<i<<"\n";
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<"\n";
	}
}
int main()
{
	freopen("replace1.in","r",stdin);
	cin>>n>>q;
		solve1();
	return 0;
}
