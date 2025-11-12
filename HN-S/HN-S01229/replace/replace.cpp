#include<bits/stdc++.h>
// #define int long long
#define filein(x) freopen(x".in","r",stdin)
#define fileout(x) freopen(x".out","w",stdout)
using namespace std;
namespace glm
{
	const int MaxN=5e6+9;
	#define lowbit(x) (x&(-x))
	struct bit
	{
		int c[MaxN];
		void add(int x,int k)
		{
			for(;x<MaxN;x+=lowbit(x))
			c[x]+=k;
		}
		int ask(int x)
		{
			int now=0;
			for(;x;x-=lowbit(x))
			now+=c[x];
			return now;
		}
		int ask(int l,int r)
		{
			return ask(r)-ask(l-1);
		}
	};
	#undef lowbit
}
using namespace glm;
bit lf;
#define ull unsigned long long
map<pair<ull,ull>,int>mp;
const int N=2e5+9,M=5e6+9;
const ull B=458791,B2=1145141;
struct Node
{
	string l,r;
	int id;
};
vector<Node>vc[N];
vector<int>d[M];
int top;
int tr[M][26],cnt,dfn[M],dnm,siz[M];
int n,q,ans[N];
pair<int,int>id[N<<1];
void dfs(int x)
{
	siz[x]=1;
	dfn[x]=++dnm;
	for(int i=0;i<26;i++)
	{
		if(tr[x][i])
		{
			dfs(tr[x][i]);
			siz[x]+=siz[tr[x][i]];
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	filein("replace");
	fileout("replace");
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		int l=-1,r=-1;
		for(int j=0;j<len;j++)
		{
			if(s1[j]!=s2[j])
			{
				if(l==-1)
				l=j;
				r=j;
			}
		}
		if(l==-1)
		continue;
		pair<ull,ull>hs={0,0};
		for(int j=l;j<=r;j++)
		{
			hs.first=hs.first*B+s1[j];
			hs.second=hs.second*B2+s2[j];
		}
		int p=0;
		if(!(p=mp[hs]))
		{
			mp[hs]=++top;
			p=top;
		}
		string L="",R="";
		for(int j=l-1;j>=0;j--)
		L+=s1[j];
		for(int j=r+1;j<len;j++)
		R+=s1[j];
		vc[p].push_back({L,R,0});
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		if(s2.size()!=len)
		continue;
		int l=-1,r=-1;
		for(int j=0;j<len;j++)
		{
			if(s1[j]!=s2[j])
			{
				if(l==-1)
				l=j;
				r=j;
			}
		}
		if(l==-1)
		continue;
		pair<ull,ull>hs={0,0};
		for(int j=l;j<=r;j++)
		{
			hs.first=hs.first*B+s1[j];
			hs.second=hs.second*B2+s2[j];
		}
		int p=mp[hs];
		// cout<<hs.first<<' '<<hs.second<<' '<<p<<'\n';
		if(!p)
		continue;
		string L="",R="";
		for(int j=l-1;j>=0;j--)
		L+=s1[j];
		for(int j=r+1;j<len;j++)
		R+=s1[j];
		vc[p].push_back({L,R,i});
	}
	for(int k=1;k<=top;k++)
	{
		for(int i=1;i<=cnt+1;i++)
		{
			memset(tr[i],0,sizeof(tr[i]));
			dfn[i]=siz[i]=0;
			d[i].clear();
		}
		cnt=1;
		dnm=0;
		int tp=0;
		for(auto u:vc[k])
		{
			int x=1;
			for(auto c:u.l)
			{
				int t=c-'a';
				assert(cnt<M);
				if(!tr[x][t])
				{
					tr[x][t]=++cnt;
				}
				x=tr[x][t];
			}
			int y=1;
			for(auto c:u.r)
			{
				int t=c-'a';
				if(!tr[y][t])
				{
					tr[y][t]=++cnt;
				}
				y=tr[y][t];
			}
			id[++tp]={x,y};
		}
		dfs(1);
		for(int i=1;i<=vc[k].size();i++)
		{
			int x=id[i].first;
			d[dfn[x]].push_back(i);
			if(vc[k][i-1].id==0)
			d[dfn[x]+siz[x]].push_back(-i);
		}
		for(int i=1;i<=cnt+1;i++)
		{
			for(auto u:d[i])
			{
				if(u<0)
				{
					int p=id[-u].second;
					lf.add(dfn[p],-1);
					lf.add(dfn[p]+siz[p],1);
				}
				else
				{
					int p=id[u].second;
					if(vc[k][u-1].id)
					{
						ans[vc[k][u-1].id]=lf.ask(dfn[p]);
					}
					else
					{
						lf.add(dfn[p],1);
						lf.add(dfn[p]+siz[p],-1);
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	cout<<ans[i]<<'\n';
	return 0;
}
/*
谐音这一块
问个失败了

(;-;)
*/