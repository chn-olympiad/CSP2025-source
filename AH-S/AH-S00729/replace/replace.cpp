#include <bits/stdc++.h>
using namespace std;
const __int128 P=1111111111111111111ll;
const __int128 B=1213141ll;
const int E=8388608;
bool operator<(pair<__int128,__int128> x,pair<__int128,__int128> y)
{
	if(x.first!=y.first) return x.first<y.first;
	return x.second<y.second;
}
map<pair<__int128,__int128>,int> roots;
int rc=0;
struct A
{
	string s;
	string t;
	bool depre;
	long long ho;
	long long hd;
	string a;
	string c;
	int na;
	int nc;
	int next;
	int ans;
	long long get_hash(string s)
	{
		__int128 res=0;
		for(int i=0;i<s.size();i++)
			res=(res*B+s[i])%P;
		return res;
	}
	void init()
	{
		if(s==t||s.size()!=t.size()) depre=true;
		if(depre) return;
		int l=0,r=s.size()-1;
		while(s[l]==t[l]) l++;
		while(s[r]==t[r]) r--;
		ho=get_hash(s.substr(l,r-l+1));
		hd=get_hash(t.substr(l,r-l+1));
		a=s.substr(0,l);
		c=s.substr(r+1,s.size()-r-1);
		reverse(a.begin(),a.end());
	}
};
A a[200012],q[200012];
struct F
{
	int to[11000012],ns[11000012],fs[11000012],m=0;
	void adds(int f,int t)
	{
		m++;
		to[m]=t;
		ns[m]=fs[f];
		fs[f]=m;
	}
	void add(int f,int t)
	{
		adds(f,t);
		adds(t,f);
	}
};
struct T3
{
	int a[8400012];
	int lowbit(int x)
	{
		return x&(-x);
	}
	void adds(int x,int v)
	{
		while(x<=E)
		{
			a[x]+=v;
			x+=lowbit(x);
		}
	}
	void add(int l,int r,int v)
	{
		adds(l,v);
		adds(r+1,-v);
	}
	int get(int x)
	{
		int ans=0;
		while(x)
		{
			ans+=a[x];
			x-=lowbit(x);
		}
		return ans;
	}
};
T3 t3;
#define ta2 (*aa)
#define tc2 (*cc)
struct T2
{
	F g;
	T2 *cc;
	int ah[5200012],qh[5200012],o[5200012],oto[5200012],oc=0;
	void dfs1(int x,int f)
	{
		oc++;
		o[x]=oc;
		int ii=g.fs[x];
		while(ii)
		{
			if(g.to[ii]!=f) dfs1(g.to[ii],x);
			ii=g.ns[ii];
		}
		oto[x]=oc;
	}
	void dfs2(int x,int f)
	{
		int h=ah[x];
		while(h)
		{
			t3.add(tc2.o[a[h].nc],tc2.oto[a[h].nc],1);
			h=a[h].next;
		}
		h=qh[x];
		while(h)
		{
			q[h].ans=t3.get(tc2.o[q[h].nc]);
			h=q[h].next;
		}
		int ii=g.fs[x];
		while(ii)
		{
			if(g.to[ii]!=f) dfs2(g.to[ii],x);
			ii=g.ns[ii];
		}
		h=ah[x];
		while(h)
		{
			t3.add(tc2.o[a[h].nc],tc2.oto[a[h].nc],-1);
			h=a[h].next;
		}
	}
};
T2 *aa,*cc;
struct T1
{
	int a[5200012][26],tc=0;
	int add_root()
	{
		tc++;
		return tc;
	}
	int add(string s,int root,bool force,T2* dest)
	{
		for(int i=0;i<s.size();i++)
		{
			if(!a[root][s[i]-'a'])
			{
				if(!force) return root;
				tc++;
				a[root][s[i]-'a']=tc;
				(*dest).g.add(root,tc);
			}
			root=a[root][s[i]-'a'];
		}
		return root;
	}
};
T1 ta1,tc1;
int main()
{
	// thinking, 15:30 - 15:55, OK
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	// Part 1: convert options and queries, 15:55 - 16:10, OK
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].t;
		a[i].init();
	}
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].s>>q[i].t;
		q[i].init();
	}
	// Part 2: build tries, 16:10 - 17:00, OK
	aa=new T2;
	memset(aa,0,sizeof(T2));
	cc=new T2;
	memset(cc,0,sizeof(T2));
	for(int i=1;i<=n;i++)
	{
		if(a[i].depre) continue;
		if(!roots.count(make_pair(a[i].ho,a[i].hd)))
		{
			roots[make_pair(a[i].ho,a[i].hd)]=ta1.add_root();
			roots[make_pair(a[i].ho,a[i].hd)]=tc1.add_root();
			rc++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].depre) continue;
		a[i].na=ta1.add(a[i].a,roots[make_pair(a[i].ho,a[i].hd)],true,aa);
		a[i].next=ta2.ah[a[i].na];
		ta2.ah[a[i].na]=i;
		a[i].nc=tc1.add(a[i].c,roots[make_pair(a[i].ho,a[i].hd)],true,cc);
	}
	for(int i=1;i<=rc;i++)
		tc2.dfs1(i,0);
	// Part 3: convert queries, 17:00 - 17:00 (Yes, instantly!), OK
	for(int i=1;i<=m;i++)
		if(!roots.count(make_pair(q[i].ho,q[i].hd))) q[i].depre=true;
	for(int i=1;i<=m;i++)
	{
		if(q[i].depre) continue;
		q[i].na=ta1.add(q[i].a,roots[make_pair(q[i].ho,q[i].hd)],false,aa);
		q[i].next=ta2.qh[q[i].na];
		ta2.qh[q[i].na]=i;
		q[i].nc=tc1.add(q[i].c,roots[make_pair(q[i].ho,q[i].hd)],false,cc);
	}
	// Part 4: DFS trie set A and calculate answers, 17:00 - 17:15, OK
	ta2.cc=cc;
	for(int i=1;i<=m;i++)
		q[i].ans=0;
	for(int i=1;i<=rc;i++)
		ta2.dfs2(i,0);
	for(int i=1;i<=m;i++)
		cout<<q[i].ans<<'\n';
	return 0;
	// testing, 17:15 - 17:30, OK
}
// 15:30 - 17:30, samples passed (455 ms), 100 / 100 points
