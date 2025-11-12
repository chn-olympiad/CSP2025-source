#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define pii pair<int,int>
#define mkp(x,y) make_pair(x,y)
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int MOD1=998244353,MOD2=998244853;
const int base1=23,base2=29;
#define filename "replace"

int n,q;

pii calcHASH(string s)
{
	int hsh1=0,hsh2=0;
	for(auto x:s)
	{
		hsh1*=base1;
		hsh2*=base2;
		hsh1+=x-'a'+1;
		hsh2+=x-'a'+1;
	}
	return mkp(hsh1,hsh2);
}

struct Node
{
	string prefix,suffix;
	pii HSH1,HSH2;
};

vector<Node>S,T;

int ans[200010];

map<pair<pii,pii>,pair<set<int>,set<int>>>se;

struct Fenwick
{
#define lowbit(x) (x&-x)
	vector<int>tr;
	int n;
	Fenwick(int _):tr(_+20),n(_+10){}
	void add(int pos,int val)
	{
		while(pos<=n)
		{
			tr[pos]+=val;
			pos+=lowbit(pos);
		}
	}
	int qry(int pos)
	{
//		cerr<<pos<<endl;
		int res=0;
		while(pos)
		{
			res+=tr[pos];
			pos-=lowbit(pos);
		}
		return res;
	}
	void fix(int l,int r,int val)
	{
//		cerr<<l<<' '<<r<<' '<<val<<endl;
		add(l,val);
		add(r+1,-val);
	}
};

// 简要记录一下这里的思路：我们对前缀和后缀分别建立 trie 树，对前缀 trie 树维护一个以 T 为下标和 Fenwick，在后缀的 trie 树上游走
// 
// 如果遇到一个 s 节点，就将前缀 trie 对应 s 节点子树范围 +1
// 如果遇到一个 t 节点，查询前缀 trie 对应 t 节点的值，计入答案。

int trieprefix[5000010][26],triesuffix[5000010][26];

vector<int>sinp[5000010],tinp[5000010],sins[5000010],tins[5000010];

int dfn[5000010],siz[5000010],dfc;

vector<int>Sonpre,Tonpre;

int resans[200010];

int tdfn[200010];

int cntpretrie,cntsuftrie;

int insertpre(string s)
{
	int now=0;
	for(auto x:s)
	{
		if(!trieprefix[now][x-'a'])trieprefix[now][x-'a']=++cntpretrie;
		now=trieprefix[now][x-'a'];
	}
	return now;
}

void dfspre(int now)
{
	dfn[now]=++dfc;
	siz[now]=1;
	for(auto x:tinp[now])tdfn[x]=dfc;
	for(int i=0;i<26;i++)if(trieprefix[now][i])
	{
		dfspre(trieprefix[now][i]);
		siz[now]+=siz[trieprefix[now][i]];
	}
}

int insertsuf(string s)
{
	int now=0;
	for(auto x:s)
	{
		if(!triesuffix[now][x-'a'])triesuffix[now][x-'a']=++cntsuftrie;
		now=triesuffix[now][x-'a'];
	}
	return now;
}

void dfssuf(int now,Fenwick &fen)
{
	for(auto x:sins[now])
	{
		int prenow=Sonpre[x];
		fen.fix(dfn[prenow],dfn[prenow]+siz[prenow]-1,1);
	}
	for(auto x:tins[now])
	{
		int prenow=Tonpre[x];
		resans[x]=fen.qry(dfn[prenow]);
	}
	for(int i=0;i<26;i++)if(triesuffix[now][i])dfssuf(triesuffix[now][i],fen);
	for(auto x:sins[now])
	{
		int prenow=Sonpre[x];
		fen.fix(dfn[prenow],dfn[prenow]+siz[prenow]-1,-1);
	}
}

void solve(set<int>sse,set<int>tse)
{
	vector<int>sid(1),tid(1);
	int tot_p_size=0,tot_s_size=0;
	for(auto x:sse)sid.push_back(x),tot_p_size+=S[x].prefix.size(),tot_s_size+=S[x].suffix.size();
	for(auto x:tse)tid.push_back(x),tot_p_size+=T[x].prefix.size(),tot_s_size+=T[x].suffix.size();
	int n=sid.size()-1,m=tid.size()-1;
//	for(auto x:tid)cerr<<x<<' ';
//	cerr<<endl;
//	vector<int>Sonpre(n+1),Tonpre(m+1);
	Sonpre.clear();
	Sonpre.resize(n+1);
	Tonpre.clear();
	Tonpre.resize(m+1);
	for(int i=1;i<=m;i++)tdfn[i]=0;
	cntpretrie=cntsuftrie=0;
	dfc=0;
	for(int i=0;i<=tot_p_size;i++)
	{
		memset(trieprefix[i],0,sizeof(trieprefix[i]));
		sinp[i].clear();
		tinp[i].clear();
	}
	for(int i=0;i<=tot_s_size;i++)
	{
		memset(triesuffix[i],0,sizeof(triesuffix[i]));
		sins[i].clear();
		tins[i].clear();
	}
	// 构建前缀 trie
	for(int i=1;i<=n;i++)
	{
		int node=insertpre(S[sid[i]].prefix);
		Sonpre[i]=node;
		sinp[node].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		int node=insertpre(T[tid[i]].prefix);
		Tonpre[i]=node;
		tinp[node].push_back(i);
	}
	dfspre(0);
	Fenwick fen(cntpretrie);
	for(int i=1;i<=n;i++)
	{
		int node=insertsuf(S[sid[i]].suffix);
		sins[node].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		int node=insertsuf(T[tid[i]].suffix);
		tins[node].push_back(i);
	}
	dfssuf(0,fen);
	for(int i=1;i<=m;i++)
	{
		ans[tid[i]]=resans[i];
	}
}


void work()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a, b;
		cin>>a>>b;
		if(a==b)continue;
		size_t l=0x3f3f3f3f,r=0;
		for(size_t i=0;i<a.size();i++)
		{
			if(a[i]!=b[i])
			{
				l=min(l,i);
				r=max(r,i);
			}
		}
		string res1,res2;
		for(size_t i=l;i<=r;i++)res1.push_back(a[i]),res2.push_back(b[i]);
		pii h1=calcHASH(res1),h2=calcHASH(res2);
		string pre,suf;
		for(size_t i=0;i<l;i++)pre.push_back(a[i]);
		for(size_t i=r+1;i<a.size();i++)suf.push_back(a[i]);
		reverse(pre.begin(),pre.end());
		S.push_back({pre,suf,h1,h2});
		se[mkp(h1,h2)].first.insert(S.size()-1);
	}
	for(int i=1;i<=q;i++)
	{
		string a, b;
		cin>>a>>b;
		if(a==b)continue;
		size_t l=0x3f3f3f3f,r=0;
		for(size_t i=0;i<a.size();i++)
		{
			if(a[i]!=b[i])
			{
				l=min(l,i);
				r=max(r,i);
			}
		}
		string res1,res2;
		for(size_t i=l;i<=r;i++)res1.push_back(a[i]),res2.push_back(b[i]);
		pii h1=calcHASH(res1),h2=calcHASH(res2);
		string pre,suf;
		for(size_t i=0;i<l;i++)pre.push_back(a[i]);
		for(size_t i=r+1;i<a.size();i++)suf.push_back(a[i]);
		reverse(pre.begin(),pre.end());
		T.push_back({pre,suf,h1,h2});
		se[mkp(h1,h2)].second.insert(T.size()-1);
	}
	for(auto x:se)
	{
		if(x.second.first.size()&&x.second.second.size())solve(x.second.first,x.second.second);
	}
	for(int i=0;i<q;i++)cout<<ans[i]<<endl;
}
signed main()
{
#ifndef LOCAL
#ifdef filename
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int t;
//	cin >> t;
	t=1;
	while (t--)
	{
		work();
	}
	return 0;
}