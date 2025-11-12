#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define N 200010
#define base1 233
#define mod1 998244353
#define base2 701
#define mod2 998244853
int n,q,cnt,ans[N];
string x[N],z[N],q1[N],q2[N];
vector<int> h1[N],h2[N];
struct node
{
	int xhsh1,xhsh2,yhsh1,yhsh2;
	node()
	{
		xhsh1=xhsh2=0;
		yhsh1=yhsh2=0;
	}
	node(pair<int,int> k1,pair<int,int> k2)
	{
		xhsh1=k1.first;
		xhsh2=k1.second;
		yhsh1=k2.first;
		yhsh2=k2.second;
	}
	friend bool operator==(node a,node b)
	{
		return a.xhsh1==b.xhsh1&&a.xhsh2==b.xhsh2&&a.yhsh1==b.yhsh1&&a.yhsh2==b.yhsh2;
	}
};
class hashT
{
	public:
		#define MoD 1000003
		vector<pair<node,int> > g[MoD];
		bool insert(node p,int k)
		{
			int xx=13ll*p.xhsh1+23ll*p.xhsh2+97ll*p.yhsh1+101ll*p.yhsh2;
			xx%=MoD;
			for(pair<node,int> w:g[xx])
			if(w.first==p)
			 return false;
			g[xx].push_back(make_pair(p,k));
			return true;
		}
		int query(node p)
		{
			int xx=13ll*p.xhsh1+23ll*p.xhsh2+97ll*p.yhsh1+101ll*p.yhsh2;
			xx%=MoD;
			for(pair<node,int> w:g[xx])
			if(w.first==p)
			 return w.second;
			return 0;
		}
}hT;
class Trie
{
	public:
		#define NN 5000010
		int cnt,tr[NN][26];
		vector<int> g[NN];
		void clear()
		{
			for(int i=1;i<=cnt;i++)
			{
				g[i].clear();
				for(int j=0;j<26;j++)
				 tr[i][j]=0;
			}
			cnt=1;
		}
		void insert(string s,int k)
		{
			int o=1;
			for(int j=0;j<s.size();j++)
			{
				if(!tr[o][s[j]-'a'])
				 tr[o][s[j]-'a']=++cnt;
				o=tr[o][s[j]-'a'];
			}
			g[o].push_back(k);
		}
		void insertpop(string s)
		{
			int o=1;
			for(int j=0;j<s.size();j++)
			{
				o=tr[o][s[j]-'a'];
			}
			g[o].pop_back();
		}
		int query(string s)
		{
			int o=1;
			int res=g[o].size();
//			cerr<<"root +++= "<<res<<endl;
			for(int j=0;j<s.size();j++)
			{
				o=tr[o][s[j]-'a'];
//				cerr<<"now "<<o<<" +++="<<g[o].size()<<endl;
				res+=g[o].size();
			}
			return res;
		}
}tr1,tr2;
void dfs1(int o)
{
	for(int k:tr1.g[o])
	if(k>0)
	{
//		cerr<<"ins "<<k<<" str "<<z[k]<<endl;
		tr2.insert(z[k],k);
	}
	else
	{
//		cerr<<"query "<<k<<" plus "<<tr2.query(q2[-k])<<" by str "<<q2[-k]<<endl;
		ans[-k]+=tr2.query(q2[-k]);
	}
	for(int j=0;j<26;j++)
	if(tr1.tr[o][j])
	 dfs1(tr1.tr[o][j]);
	for(int k:tr1.g[o])
	if(k>0)
	{
//		cerr<<"pop "<<k<<" str "<<z[k]<<endl;
		tr2.insertpop(z[k]);
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>z[i];
		int mn=1000000000,mx=-1;
		for(int j=0;j<x[i].size();j++)
		if(x[i][j]!=z[i][j])
		{
			mn=min(mn,j);
			mx=max(mx,j);
		}
		if(mn>mx)
		 continue;
		pair<int,int> k1=make_pair(0,0),k2=make_pair(0,0);
		for(int j=mn;j<=mx;j++)
		{
			k1.first=(1ll*k1.first*base1+x[i][j])%mod1;
			k1.second=(1ll*k1.second*base2+x[i][j])%mod2;
			k2.first=(1ll*k2.first*base1+z[i][j])%mod1;
			k2.second=(1ll*k2.second*base2+z[i][j])%mod2;
		}
		cnt++;
		node qwq(k1,k2);
		if(!hT.insert(qwq,cnt))
		 cnt--;
		int id=hT.query(qwq);
//		cerr<<"opt "<<i<<" to "<<id<<endl;
		h1[id].push_back(i);
		if(mn>0)
		 x[i]=x[i].substr(0,mn);
		else
		 x[i]="";
		if(mx<z[i].size()-1)
		 z[i]=z[i].substr(mx+1,z[i].size()-mx-1);
		else
		 z[i]="";
	}
	for(int i=1;i<=q;i++)
	{
		cin>>q1[i]>>q2[i];
		if(q1[i].size()!=q2[i].size())
		 continue;
		int mn=1000000000,mx=-1;
		for(int j=0;j<q1[i].size();j++)
		if(q1[i][j]!=q2[i][j])
		{
			mn=min(mn,j);
			mx=max(mx,j);
		}
		if(mn>mx)
		 continue;
		pair<int,int> k1=make_pair(0,0),k2=make_pair(0,0);
		for(int j=mn;j<=mx;j++)
		{
			k1.first=(1ll*k1.first*base1+q1[i][j])%mod1;
			k1.second=(1ll*k1.second*base2+q1[i][j])%mod2;
			k2.first=(1ll*k2.first*base1+q2[i][j])%mod1;
			k2.second=(1ll*k2.second*base2+q2[i][j])%mod2;
		}
		node qwq(k1,k2);
		int id=hT.query(qwq);
//		cerr<<"query "<<i<<" to "<<id<<endl;
		if(!id)
		 continue;
		h2[id].push_back(i);
		if(mn>0)
		 q1[i]=q1[i].substr(0,mn);
		else
		 q1[i]="";
		if(mx<q2[i].size()-1)
		 q2[i]=q2[i].substr(mx+1,q2[i].size()-mx-1);
		else
		 q2[i]="";
	}
	for(int i=1;i<=cnt;i++)
	{
//		cerr<<"----- now id="<<i<<endl;
		tr1.clear();
		for(int pos:h1[i])
		{
			reverse(x[pos].begin(),x[pos].end());
			tr1.insert(x[pos],pos);
		}
		for(int pos:h2[i])
		{
			reverse(q1[pos].begin(),q1[pos].end());
			tr1.insert(q1[pos],-pos);
		}
		tr2.clear();
		dfs1(1);
	}
	for(int i=1;i<=q;i++)
	 cout<<ans[i]<<"\n";
}
