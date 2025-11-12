// GZ-00334 王曦 贵阳华师一学校 
#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x=0; bool f=0; char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}

#define x first
#define y second
#define pb emplace_back
#define upb upper_bound
#define lowb lower_bound
#define fil(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)

/*
我怎么感觉，直接哈希一下就好了
哦那好像并不是
注意哈希避免碰撞 
*/

typedef long long LL;
typedef vector<int> VI;
typedef unsigned int ull; 
typedef pair<int,int> PII;
const int N=4e5+10,M=5e6+10;

int n,Q,m;
char A[N],B[N];
int ans[N];

const LL P1=131,P2=157,P3=151;
const LL M1=1e9+123,M2=1e9+9,M3=998244353;
struct Node {
	LL h1,h2,h3;
	void add(char c) {h1=(h1*P1+c)%M1,h2=(h2*P2+c)%M2,h3=(h3*P3+c)%M3;}
	bool operator==(Node &B) {return h1==B.h1 && h2==B.h2 && h3==B.h3;}
	bool operator<(const Node &B) const{
		if(h1!=B.h1) return h1<B.h1;
		if(h2!=B.h2) return h2<B.h2;
		return h3<B.h3;
	}
	bool operator>(const Node &B) const{
		if(h1!=B.h1) return h1>B.h1;
		if(h2!=B.h2) return h2>B.h2;
		return h3>B.h3;
	}
};
map<Node,int> f;

int rt[N],idx,id;
int ch[M][26];
int ins(int p,int c) {return ch[p][c]?ch[p][c]:(ch[p][c]=++idx);}

int p[N],q[N];
int dfn[M],L[M],R[M],tot;
void dfs(int u) {
	dfn[u]=L[u]=R[u]=++tot;
	rep(i,0,25) if(ch[u][i]) dfs(ch[u][i]),R[u]=tot;
}
struct Qry{int l,r,v;}; vector<Qry> opt[M],qry[M];
int tr[M];
void add(int x,int v) {for(;x<=tot;x+=(x&-x)) tr[x]+=v;}
int ask(int x) {int res=0; for(;x;x-=(x&-x)) res+=tr[x]; return res;}

signed main() 
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>Q;
	rep(o,1,n) {
		cin>>(A+1)>>(B+1);
		int len=strlen(A+1),l=0,r=0;
		rep(i,1,len) if(A[i]!=B[i]) {if(!l) l=i; r=i;}
		if(!l) continue;
		++m; Node t; t.h1=t.h2=t.h3=0;
		rep(i,l,r) t.add(A[i]);
		t.add('$');
		rep(i,l,r) t.add(B[i]);
		if(!f[t]) f[t]=++id;
		int cur=f[t]; if(!rt[cur]) rt[cur]=++idx;
		cur=rt[cur]; per(i,l-1,1) cur=ins(cur,A[i]-'a');
		p[m]=cur;
		cur=f[t]+n; if(!rt[cur]) rt[cur]=++idx;
		cur=rt[cur]; rep(i,r+1,len) cur=ins(cur,A[i]-'a');
		q[m]=cur;
	}
//	cerr<<111<<"\n";
	rep(i,1,id) dfs(rt[i]),dfs(rt[i+n]);
//	cerr<<111<<"\n";
	rep(i,1,m) {
		int l1=L[p[i]],r1=R[p[i]],l2=L[q[i]],r2=R[q[i]];
		opt[l1].pb((Qry){l2,r2,1});
		opt[r1+1].pb((Qry){l2,r2,-1});
	}
//	cerr<<111<<"\n";
	
	rep(i,1,Q) {
		cin>>(A+1)>>(B+1);
		int len=strlen(A+1),l=0,r=0;
		rep(i,1,len) if(A[i]!=B[i]) {if(!l) l=i; r=i;}
		Node t; t.h1=t.h2=t.h3=0;
		rep(i,l,r) t.add(A[i]);
		t.add('$');
		rep(i,l,r) t.add(B[i]);
		if(!f[t]) {ans[i]=0; continue;}
		int x=rt[f[t]],y=rt[f[t]+n];
		per(i,l-1,1) {
			if(ch[x][A[i]-'a']) x=ch[x][int(A[i]-'a')];
			else break;
		}
		rep(i,r+1,len) {
			if(ch[y][A[i]-'a']) y=ch[y][A[i]-'a'];
			else break;
		}
		qry[dfn[x]].pb((Qry){dfn[y],0,i});
	}
//	cerr<<111<<"\n";
	rep(i,1,tot) {
		for(Qry t:opt[i]) add(t.l,t.v),add(t.r+1,-t.v);
		for(Qry t:qry[i]) ans[t.v]=ask(t.l);
	}
//	cerr<<111<<"\n";
	rep(i,1,Q) cout<<ans[i]<<"\n";
	
//	cerr<<clock()*1.0/CLOCKS_PER_SEC<<"\n";
	return 0;
}

