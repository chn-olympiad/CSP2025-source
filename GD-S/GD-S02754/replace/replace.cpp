#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,q,ans[200011];
struct ps
{
	string a,b,pre,suf;
	int i,l,r,id;
	pair<unsigned long long,unsigned long long> dha,dhb;
	bool inval;
}a[200011],b[200011];
void bd(ps &a)
{
	int l=-1,r=-1;
	if(a.a.size()!=a.b.size())
	{
		a.inval=1;
		return;
	}
	for(int i=0;i<a.a.size();i++)
	{
		if(a.a[i]!=a.b[i])
		{
			r=i;
			if(l==-1) l=i;
		}
	}
	if(l==-1)
	{
		a.inval=1;
		return;
	}
	for(int i=l;i<=r;i++)
	{
		a.dha.first*=131;
		a.dha.second*=1331;
		a.dhb.first*=131;
		a.dhb.second*=1331;
		a.dha.first+=a.a[i]-'a';
		a.dha.second+=a.a[i]-'a';
		a.dhb.first+=a.b[i]-'a';
		a.dhb.second+=a.b[i]-'a';
	}
	for(int i=l-1;i>=0;i--)
	{
		a.pre+=a.a[i];
	}
	for(int i=r+1;i<a.a.size();i++)
	{
		a.suf+=a.a[i];
	}
	a.l=l,a.r=r;
}
bool cmp(ps a,ps b)
{
	if(a.dha==b.dha) return a.dhb<b.dhb;
	return a.dha<b.dha;
}
namespace HAP
{
	int smm[3000001],N;
	void add(int x,int v)
	{
//		cout<<"ADD "<<x<<" "<<v<<"\n";
		while(x<=N)
		{
			smm[x]+=v;
			x+=(x&(-x));
		}
	}
	int get(int x)
	{
		int ret=0;
		while(x)
		{
			ret+=smm[x];
			x-=(x&(-x));
		}
		return ret;
	}
	struct T
	{
		int nxt[26],dfn;
	}ac[3000001];
	int p,L[200011],R[200011],W[200011],LEN;
	vector <int> ap[3000001],bp[3000001];
	void ins(string a,int id)
	{
		int P=0;
		for(int i=0;i<a.size();i++)
		{
			if(!ac[P].nxt[a[i]-'a'])
			{
				ac[P].nxt[a[i]-'a']=++p;
			}
			P=ac[P].nxt[a[i]-'a'];
		}
		ap[P].push_back(id);
	}
	void ins2(string a,int id)
	{
		int P=0;
		for(int i=0;i<a.size();i++)
		{
			if(!ac[P].nxt[a[i]-'a'])
			{
				break;
			}
			bp[P].push_back(id);
			P=ac[P].nxt[a[i]-'a'];
		}
		bp[P].push_back(id);
	}
	void geow(string a,int id)
	{
		int P=0;
		for(int i=0;i<a.size();i++)
		{
			if(!ac[P].nxt[a[i]-'a'])
			{
				break;
			}
			P=ac[P].nxt[a[i]-'a'];
		}
		W[id]=ac[P].dfn;
	}
	void getdfn(int u)
	{
		LEN++;
		ac[u].dfn=LEN;
		for(int w:ap[u]) L[w]=LEN;
		for(int i=0;i<26;i++)
		{
			if(ac[u].nxt[i])
			getdfn(ac[u].nxt[i]);
		}
		for(int w:ap[u]) R[w]=LEN;
	}
	void getans(int u)
	{
		for(int w:ap[u]) add(L[w],1),add(R[w]+1,-1);
		for(int w:bp[u])
		{
			ans[w]+=get(W[w]);
//			cout<<w<<" "<<u<<" : "<<get(W[w])<<"\n";
		}
		for(int w:ap[u]) add(L[w],-1),add(R[w]+1,1);
		for(int i=0;i<26;i++)
		{
			if(ac[u].nxt[i])
			getans(ac[u].nxt[i]);
		}
	}
	void work(vector <ps> a,vector <ps> b)
	{
		if(a.empty()||b.empty()) return;
		//pre
		for(int i=0;i<=p;i++)
		{
			ap[i].clear();
			bp[i].clear();
			for(int z=0;z<26;z++) ac[i].nxt[z]=0;
		}
		p=0;
		LEN=0;
//		bool fnd=0;
//		for(ps w:b) if(w.i==51)
//		{
//			fnd=1;
//			cerr<<"WORK::\n";
//			for(ps w:a) cerr<<w.a<<" "<<w.b<<"\n";
//			cerr<<":::\n";
//			for(ps w:b) cerr<<w.a<<" "<<w.b<<"\n";
//			cerr<<"------\n";
//		}
		int len=0;
		for(ps &w:a) w.id=++len;
		for(ps w:a)
		{
			ins(w.pre,w.id);
		}
		getdfn(0);
		for(ps w:b)
		{
			geow(w.pre,w.i);
		}
		N=LEN;
		//suf
		for(int i=0;i<=p;i++)
		{
			ap[i].clear();
			bp[i].clear();
			for(int z=0;z<26;z++) ac[i].nxt[z]=0;
		}
		p=0;
		LEN=0;
		for(ps w:a)
		{
//			if(fnd) cerr<<L[w.id]<<" "<<R[w.id]<<"\n";
			ins(w.suf,w.id);
		}
		for(ps w:b)
		{
//			if(fnd) cerr<<W[w.i]<<"\n";
			ins2(w.suf,w.i);
		}
//		if(fnd) cerr<<ans[51];
		getans(0);
//		if(fnd) cerr<<ans[51];
	}
}
signed main()
{
//	freopen("replace2.in","r",stdin);
//	freopen("replace2.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].b;
		bd(a[i]);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i].a>>b[i].b;
//		if(i==51) cerr<<b[i].a<<" "<<b[i].b<<"\n";
		b[i].i=i;
		bd(b[i]);
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+q+1,cmp);
	vector <ps> na,nb;
	int zz=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i].inval) continue;
		na.push_back(a[i]);
		if(i==n||(a[i].dha!=a[i+1].dha||a[i].dhb!=a[i+1].dhb))
		{
			while(zz<=q&&b[zz].dha<a[i].dha) zz++;
			while(zz<=q&&b[zz].dha==a[i].dha&&b[zz].dhb<=a[i].dhb)
			{
				if(!b[zz].inval&&b[zz].dhb==a[i].dhb)
				{
					nb.push_back(b[zz]);
				}
				zz++;
			}
			HAP::work(na,nb);
			na.clear();
			nb.clear();
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<"\n";
	}
//	cerr<<ans[51];
}
/*
哦
替换一个区间问可以吗
那我找到严格需要替换子串
然后做一个字符串匹配类似物品
而且前后都要匹配上
那我可以求出前匹配集合和后匹配集合，求并
其实集合可以很大
偷懒的话可以使用 bitset
相当于给你树上很多pair，一个 pair 对下面所有询问产生贡献
相当于对落在两个区间内的询问产生贡献
离线下来扫描线？
可以
相当难的题？ 
*/
