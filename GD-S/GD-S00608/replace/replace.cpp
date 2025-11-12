#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL M=5e6+10,N=2e5+10,Q1=133331,P1=998244353,Q2=1573,P2=1e9+7;
LL n,q,tot,ans[N];
char s[M],t[M];
struct hsh { LL a,b,c,d; };
map<hsh,LL> id;
bool operator <(hsh x,hsh y)
{
	if(x.a!=y.a) return x.a<y.a;
	if(x.b!=y.b) return x.b<y.b;
	if(x.c!=y.c) return x.c<y.c;
	if(x.d!=y.d) return x.d<y.d;
	return 0;
}
vector<vector<char>> ly[N*2],zxz[N*2];
vector<vector<char>> pre[N*2],suf[N*2];
vector<LL> qid[N*2];
void deco()
{
	LL m=strlen(s+1),l=m+1,r=0;
	for(LL i=1;i<=m;i++) if(s[i]!=t[i]) l=min(l,i),r=max(r,i);
	LL A=0,B=0,C=0,D=0;
	if(!r) return;
	for(int i=l;i<=r;i++) A=(A*Q1+s[i])%P1,B=(B*Q1+t[i])%P1,C=(C*Q2+s[i])%P2,D=(D*Q2+t[i])%P2;
	if(!id[{A,B,C,D}]) id[{A,B,C,D}]=++tot;
	LL x=id[{A,B,C,D}];
	ly[x].push_back({});
	zxz[x].push_back({});
	for(int i=l-1;i>=1;i--) ly[x].back().push_back(s[i]);
	for(int i=r+1;i<=m;i++) zxz[x].back().push_back(s[i]);
}
void Mike(LL y)
{
	LL m=strlen(s+1),l=m+1,r=0;
	for(LL i=1;i<=m;i++) if(s[i]!=t[i]) l=min(l,i),r=max(r,i);
	LL A=0,B=0,C=0,D=0;
	for(int i=l;i<=r;i++) A=(A*Q1+s[i])%P1,B=(B*Q1+t[i])%P1,C=(C*Q2+s[i])%P2,D=(D*Q2+t[i])%P2;
	if(!id[{A,B,C,D}]) id[{A,B,C,D}]=++tot;
	LL x=id[{A,B,C,D}];
	pre[x].push_back({});
	suf[x].push_back({});
	for(int i=l-1;i>=1;i--) pre[x].back().push_back(s[i]);
	for(int i=r+1;i<=m;i++) suf[x].back().push_back(s[i]);
	qid[x].push_back(y);
}
map<int,int> vis;
struct DS
{
	int cnt[M],tot,tr[M][26],dfn[M],ed[M],Dt,id[M];
	void clr()
	{
		for(int i=0;i<=tot;i++) cnt[i]=0,memset(tr[i],0,sizeof(tr[i]));
		tot=Dt=0;
	}
	void ins(vector<char> &s,int x)
	{
		int u=0;
		for(int i=0;i<(int)s.size();i++)
		{
			int &v=tr[u][s[i]-'a'];
			if(!v) v=++tot;
			u=v;
		}
		cnt[u]++; id[x]=u;
	}
	void dfs(int u=0)
	{
		dfn[u]=++Dt;
		for(int i=0;i<26;i++) if(tr[u][i]) dfs(tr[u][i]);
		ed[u]=Dt;
	}
	int query(vector<char> &s)
	{
		int u=0;
		for(int i=0;i<(int)s.size();i++)
		{
			int v=tr[u][s[i]-'a'];
			if(!v) return dfn[u];
			u=v;
		}
		return dfn[u];
	}
}Tp,Ts;
struct OP { LL op,x,l,r,val; }tk[N*3]; LL sst;
bool cmp(OP a,OP b) { return a.x==b.x?a.op<b.op:a.x<b.x; }
LL c[M];
void upd(LL x,LL val) { for(;x<M;x+=x&(-x)) c[x]+=val; }
LL ask(LL x) { LL res=0; for(;x;x&=x-1) res+=c[x]; return res; }
void shiroko()
{
	sort(tk+1,tk+sst+1,cmp);
	for(int i=1;i<=sst;i++)
	{
		if(tk[i].op==1) upd(tk[i].l,tk[i].val),upd(tk[i].r+1,-tk[i].val);
		else ans[tk[i].val]=ask(tk[i].l);
	}
}
//bool check(vector<char> a,vector<char> b)
//{
//	if(a.size()>b.size()) return 0;
//	for(int i=0;i<a.size();i++)
//		if(a[i]!=b[i]) return 0;
//	return 1;
//}
//bool check(LL l,LL r,LL x)
//{
//	return l<=x&&x<=r;
//}
void solve()
{
	for(int $=1;$<=tot;$++)
	{
//		for(int i=0;i<(int)pre[$].size();i++)//brute 1
//		{
//			for(int j=0;j<(int)ly[$].size();j++)
//				ans[qid[$][i]]+=check(ly[$][j],pre[$][i])&&check(zxz[$][j],suf[$][i]);
//		}
		Tp.clr(),Ts.clr();
		for(int i=0;i<(int)ly[$].size();i++) Tp.ins(ly[$][i],i),Ts.ins(zxz[$][i],i);
		Tp.dfs(),Ts.dfs(); sst=0;
//		for(int i=0;i<(int)pre[$].size();i++)//brute 2
//		{
//			for(int j=0;j<(int)ly[$].size();j++)
//				ans[qid[$][i]]+=check(Tp.dfn[Tp.id[j]],Tp.ed[Tp.id[j]],Tp.query(pre[$][i]))&&
//				check(Ts.dfn[Ts.id[j]],Ts.ed[Ts.id[j]],Ts.query(suf[$][i]));
//		}
		for(int i=0;i<(int)ly[$].size();i++)
		{
			LL l1=Tp.dfn[Tp.id[i]],r1=Tp.ed[Tp.id[i]];
			LL l2=Ts.dfn[Ts.id[i]],r2=Ts.ed[Ts.id[i]];
			tk[++sst]={1,l1,l2,r2,1};
			tk[++sst]={1,r1+1,l2,r2,-1};
		}
		for(int i=0;i<(int)pre[$].size();i++) tk[++sst]={2,Tp.query(pre[$][i]),Ts.query(suf[$][i]),350,qid[$][i]};
		shiroko();
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++) scanf("%s%s",s+1,t+1),deco();
	for(int i=1;i<=q;i++) scanf("%s%s",s+1,t+1),Mike(i);
	solve();
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}
