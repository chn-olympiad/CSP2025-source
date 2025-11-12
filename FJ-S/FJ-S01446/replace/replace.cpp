#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define fr first
#define sc second
const int N=2e5+10,M=5e6+10;
bool sst;
int n,q,m,ct[M];
LL ans[N];
struct node
{
	int z,x,y,l,r;
	bool operator<(const node &X)
	{
		if (z==X.z) return r>X.r;
		return z>X.z;
	}
	void out()
	{
		cerr<<z<<" "<<x<<" "<<y<<" "<<l<<" "<<r<<endl;
	}
}op[N+M];
struct CDQ
{
	int x,l,r,z;
	bool operator<(const CDQ &X)const
	{
		if (x==X.x) return r>X.r;
		return x<X.x;
	}
}f[2*N+M];
string s1[N],s2[N],t1[N],t2[N];
struct AC
{
	int rt,tot,df;
	int tr[M][26],fail[M],dfn[M],out[M],dp[M],dmp[M],tl[M];
	vector<int> ver[M];
	void init()
	{
		rt=++tot;
		fail[0]=1;
		fill(tr[0],tr[0]+26,1);
	}
	void irt(string &a)
	{
		int p=rt,ln=a.size();
		for (int i=0;i<ln;i++)
		{
			if (!tr[p][a[i]-'a']) tr[p][a[i]-'a']=++tot;
//			cerr<<p<<" "<<tr[p][a[i]-'a']<<" "<<a[i]<<endl;
			p=tr[p][a[i]-'a'];
			tl[p]=i+1;
		}
	}
	void dfs(int x=1)
	{
		dfn[x]=++df;
		dmp[df]=x;
		for (int y:ver[x])
			dp[y]=dp[x]+1,dfs(y);
		out[x]=df;
	}
	void build()
	{
		queue<int> qe;
		qe.push(rt);
		while (!qe.empty())
		{
			int u=qe.front(); qe.pop();
			for (int i=0;i<26;i++)
			{
				int &v=tr[u][i];
				if (v) fail[v]=tr[fail[u]][i],qe.push(v),ver[fail[v]].push_back(v);
				else v=tr[fail[u]][i];
			}
		}
		dfs();
	}
	void print(int x=1)
	{
		cerr<<x<<" "<<dfn[x]<<" "<<out[x]<<" "<<dp[x]<<endl;
		for (int y:ver[x])
			cerr<<x<<"->"<<y<<endl,print(y);
	}
}d1,d2;
int c[M],U;
void change(int x,int y)
{
	for (;x<=U;x+=x&-x) c[x]+=y;
}
int ask(int x)
{
	int res=0;
	for (;x>0;x-=x&-x) res+=c[x];
	return res;
}
void solve(int l,int r)
{
	if (l==r) return;
	int mid=l+r>>1,ln=0,T0,T1;
	for (int i=l;i<=mid;i++)
		if (op[i].r)
			f[++ln]=(CDQ){op[i].x,op[i].l,op[i].r,1},
			f[++ln]=(CDQ){op[i].y+1,op[i].l,op[i].r,-1};
	T0=ln;
	for (int i=mid+1;i<=r;i++)
		if (!op[i].r)
			f[++ln]=(CDQ){op[i].x,op[i].y,0,op[i].l};
	T1=ln-T0;
	sort(f+1,f+ln+1);
	if (T0&&T1)
	{
//		cerr<<l<<" ^^^ "<<mid<<" "<<r<<endl;
		for (int i=1;i<=ln;)
		{
			int p=i;
			while (p<=ln&&f[p].x==f[i].x)
			{
				if (f[p].r) change(f[p].l,f[p].z),change(f[p].r+1,-f[p].z);
				else ans[f[p].z]+=ask(f[p].l);
				p++;
			}
			i=p;
		}
	}
	if (T0) solve(l,mid);
	if (T1) solve(mid+1,r);
}
bool eed;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cerr<<fabs(&eed-&sst)/1024/1024<<endl;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int al1=0,al2=0;
	d1.init(),d2.init();
	for (int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		al1+=s1[i].size();
		d1.irt(s1[i]);
		d2.irt(s2[i]);
	}
	for (int i=1;i<=q;i++)
		cin>>t1[i]>>t2[i],al2+=t1[i].size();
	d1.build(),d2.build();
//	d1.print(),d2.print();
	for (int i=1;i<=n;i++)
	{
		int ln=s1[i].size(),p1=1,p2=1;
		for (int j=0;j<ln;j++)
		{
			p1=d1.tr[p1][s1[i][j]-'a'];
			p2=d2.tr[p2][s2[i][j]-'a'];
		}
//		cerr<<i<<" --- "<<p1<<" "<<p2<<endl;
		int l=d2.dfn[p2],r=d2.out[p2];
		op[++m]=(node){ln,d1.dfn[p1],d1.out[p1],l,r};
	}
	for (int i=1;i<=q;i++)
	{
		int ln=t1[i].size(),p1=1,p2=1,l=0,r=ln-1;
		while (l<ln&&t1[i][l]==t2[i][l]) l++;
		while (r>=0&&t1[i][r]==t2[i][r]) r--;
		for (int j=0;j<ln;j++)
		{
			p1=d1.tr[p1][t1[i][j]-'a'];
			p2=d2.tr[p2][t2[i][j]-'a'];
			if (j>=r)
			{
				if (l>r)
					op[++m]=(node){1,d1.dfn[p1],d2.dfn[p2],i,0};
				else
					op[++m]=(node){j-l+1,d1.dfn[p1],d2.dfn[p2],i,0};
			}
		}
//		cerr<<i<<" ??? "<<p1<<" "<<p2<<endl;
//		if (d1.tl[p1]!=ln||d2.tl[p2]!=ln) continue;
//		cerr<<i<<" "<<d1.dfn[p1]<<" "<<d1.out[p1]<<" "<<d2.dfn[p2]<<" "<<d2.out[p2]<<endl;
	}
	U=d2.tot;
	sort(op+1,op+m+1);
//	cerr<<m<<endl;
//	for (int i=1;i<=m;i++)
//		op[i].out();
	solve(1,m);
	for (int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	cerr<<al1<<" "<<al2<<endl;
	return 0;
}
