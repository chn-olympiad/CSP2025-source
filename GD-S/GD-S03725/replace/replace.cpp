#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std; bool MEM;
using ll=long long; using ld=long double;
using pii=pair<int,int>; using pll=pair<ll,ll>;
const int I=1e9,N=2e5+7,M=2.5e6+7+N*2,K=26,L=1100000;
const ll J=1e18,P=1004535809;
const pll B={998244353,1000000007}; pll pw[M];
int lx[N*2],xl,ly[N*2],yl;
int n,q,tp[N],typ[N],ans[N];
struct lim { int l1,r1,l2,r2; } b[N];
struct sni { int l,r,z; };
char s[M],t[M],inp[M];
map<pll,int> mp; list<int> cl[M]; int cn;
int tr[M][K],rt[N*2][2],cnn,dfn[M],dfm[M],co[M];
int ins(int n,char *s,int p,int o=0) {
	for (int i=1;i<=n;i++) {
		int &x=tr[p][s[i]-'a'];
		if (!x) {
			if (o) return p;
			x=++cnn;
			cl[p].pb(cnn);
		}
		p=x;
	}
	return p;
}
void dfs(int p) {
	dfn[p]=++cnn,co[cnn]=p;
	for (int i:cl[p]) dfs(i);
	dfm[p]=cnn;
}
vector<pii> v[L],vv[L];
void add(int x,int y,pii z,int p=1,int l=1,int r=xl) {
	if (x<=l&&r<=y) return v[p].pb(z);
	int mid=l+r>>1;
	if (x<=mid) add(x,y,z,p<<1,l,mid);
	if (y>mid) add(x,y,z,p<<1|1,mid+1,r);
}
void dda(int x,pii z,int p=1,int l=1,int r=xl) {
	vv[p].pb(z);
	if (l==r) return;
	int mid=l+r>>1;
	x<=mid?dda(x,z,p<<1,l,mid):dda(x,z,p<<1|1,mid+1,r);
}
struct bit {
	int t[N*2];
	void add(int x,int z) { for (;x<=yl;x+=x&-x) t[x]+=z; }
	void add(int l,int r,int z) { add(l,z),add(r+1,-z); }
	int que(int x) { int ret=0; for (;x;x-=x&-x) ret+=t[x]; return ret; }
} T;
void dac(int p=1,int l=1,int r=xl) {
	if (v[p].size()&&vv[p].size()) {
		for (pii i:v[p]) T.add(i.fi,i.se,1);
		for (pii i:vv[p]) ans[i.se]+=T.que(i.fi);
		for (pii i:v[p]) T.add(i.fi,i.se,-1);
	}
	if (l==r) return;
	int mid=l+r>>1;
	dac(p<<1,l,mid),dac(p<<1|1,mid+1,r);
}
void mian() {
	scanf("%d%d",&n,&q);
	int sum=0;
	for (int i=1;i<=n;i++) {
		scanf("%s%s",s+1,t+1); int sz=strlen(s+1);
		sum+=sz;
		int l=0,r=0; for (int j=1;j<=sz;j++) if (s[j]!=t[j]) { l=j; break; }
		if (!l) continue;
		for (int j=sz;j;j--) if (s[j]!=t[j]) { r=j; break; }
		pll w={0,0}; int tmp=0; for (int j=l;j<=r;j++)
			{ ll tt=(ll)s[j]*128+(ll)t[j]; w={(w.fi*B.fi+tt)%P,(w.se*B.se+tt)%P}; }
		if (!mp.count(w)) mp[w]=tp[i]=++cn,rt[tp[i]][0]=++cnn,rt[tp[i]][1]=++cnn;
		else tp[i]=mp[w];
		tmp=0; for (int j=l-1;j;j--) inp[++tmp]=s[j];
		b[i].l1=ins(tmp,inp,rt[tp[i]][0]);
//		for (int j=1;j<=tmp;j++) printf("%c",inp[j]); printf("\n");
		tmp=0; for (int j=r+1;j<=sz;j++) inp[++tmp]=s[j];
		b[i].l2=ins(tmp,inp,rt[tp[i]][1]);
//		for (int j=1;j<=tmp;j++) printf("%c",inp[j]); printf("\n");
//		printf("%d %d %d %d %d %d\n",sz,l,r,tp[i],b[i].l1,b[i].l2);
	}
	cerr<<sum<<"\n";
	for (int i=1;i<=cn;i++) dfs(rt[i][0]),dfs(rt[i][1]);
	for (int i=1;i<=n;i++) if (b[i].l1) {
		b[i].r1=dfm[b[i].l1],b[i].l1=dfn[b[i].l1],b[i].r2=dfm[b[i].l2],b[i].l2=dfn[b[i].l2];
//		printf("%d %d %d %d\n",b[i].l1,b[i].r1,b[i].l2,b[i].r2);
		b[i].l1--,b[i].l2--;
		lx[++xl]=b[i].l1,lx[++xl]=b[i].r1,ly[++yl]=b[i].l2,ly[++yl]=b[i].r2;
	}
	sort(lx+1,lx+xl+1),xl=unique(lx+1,lx+xl+1)-1-lx;
	sort(ly+1,ly+yl+1),yl=unique(ly+1,ly+yl+1)-1-ly;
	auto fx=[&](int &x){x=lower_bound(lx+1,lx+xl+1,x)-lx;};
	auto fy=[&](int &x){x=lower_bound(ly+1,ly+yl+1,x)-ly;};
	for (int i=1;i<=n;i++) if (b[i].r1) {
		fx(b[i].l1),fx(b[i].r1),fy(b[i].l2),fy(b[i].r2);
		b[i].l1++,b[i].l2++;
//		printf(" %d %d %d %d\n",b[i].l1,b[i].r1,b[i].l2,b[i].r2);
		add(b[i].l1,b[i].r1,{b[i].l2,b[i].r2});
	}
	for (int i=1;i<=q;i++) {
		scanf("%s%s",s+1,t+1); int sz=strlen(s+1);
		int l=0,r=0; for (int j=1;j<=sz;j++) if (s[j]!=t[j]) { l=j; break; }
		for (int j=sz;j;j--) if (s[j]!=t[j]) { r=j; break; }
		pll w={0,0}; int tmp=0; for (int j=l;j<=r;j++)
			{ ll tt=(ll)s[j]*128+(ll)t[j]; w={(w.fi*B.fi+tt)%P,(w.se*B.se+tt)%P}; }
		if (!mp.count(w)) continue;
		typ[i]=mp[w];
		tmp=0; for (int j=l-1;j;j--) inp[++tmp]=s[j];
		int t1=dfn[ins(tmp,inp,rt[typ[i]][0],1)];
		tmp=0; for (int j=r+1;j<=sz;j++) inp[++tmp]=s[j];
		int t2=dfn[ins(tmp,inp,rt[typ[i]][1],1)];
		fx(t1),fy(t2);
//		printf("  %d %d %d %d %d\n",typ[i],l,r,t1,t2);
		dda(t1,{t2,i});
	}
	cerr<<cnn<<"\n";
	dac();
	for (int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
bool ORY; int main() {
	pw[0]={1,1}; for (int i=1;i<M;i++) pw[i]={pw[i-1].fi*B.fi%P,pw[i-1].se*B.se%P};
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	while (1)
//	int t; for (scanf("%d",&t);t--;)
	mian();
	cerr<<"\n"<<abs(&MEM-&ORY)/1048576<<"MB";
	return 0;
}
/*
5 1
cx cy
cxd cyd
labcxde labcyde
cxdef cydef
abcx abcy
abcxdef abcydef

2G？ 

给定 n 对字符串。q 次询问，每次问能否通过将 s 中的一个字符串按给定的东西进行替换得到字符串 t
哦？有意思

考虑 s 和 t 不一样的部分
那么置换串对两边一定恰好是这个部分不一致，不然就废了 
那好做多了。 

对每个置换串对尝试哈希一个什么东西，表示两边不一致的部分的极小子串 

然后查询时也来个哈希。然后我们只需要处理哈希结果匹配上的东西
那问题来了。不一致的部分以外的要怎么办？
这一部分就不取决于 t 是什么了，而是 s1,s2 延伸到的部分能不能和 t 匹配上
AC 自动机？？？？

这么恐怖吗？

对每个 s 的前后缀一致部分建 ACAM，然后拿 t 的前后缀一致部分去配
要求 s 部分是 t 部分的前缀，且前后两侧都是 
啊？
哦前缀询问不是 ACAM。只是个 Trie。 
但还是挺怪异的。

考虑在第一棵 Trie 上跑，然后对于遇到的 s_i，判断它在第二棵 Trie 上是否也符合条件
（先对 s 去重。）
哦去了重就对了。在第二棵 Trie 上也这么做一下。标记所有正确的 s_i。 
骇死我力。
感觉想太久了。复杂度是 O(nlog + L) 
最后一个问题：
L*26 有点大。。
难道这就是开 2GB 的原因吗。

不对不对不对去重根本没有解决问题
先别急。
两棵树上有一些点对，给定两条链，问两端都在给定的链上的点对数
相当于每个 s_i 有一些 [l1,r1],[l2,r2]
每个 t_i 是 [t1,t2]
求 l1<=t1<=r1 且 l2<=t2<=r2 的 s_i 数
几维偏序啊这是
反正应该可以 2log cdq 吧，应该。

算了。cdq 不好做。线段树分治。 
*/
