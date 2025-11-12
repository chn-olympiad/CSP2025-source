#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<string>
#include<bitset>
#include<cstring>
#include<numeric>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2e5+10;
const int N=2e5;
const int INF=0x3f3f3f3f;
const long long LINF=0x3f3f3f3f3f3f3f3f;
int n,m;
string s[MAXN][2],t[MAXN][2];
#define ull unsigned long long
map <pair<ull,ull>,int> tb;
int idx=0;
basic_string <int> S[MAXN<<1],T[MAXN<<1];
int ans[MAXN];
const ull seed=372409;
inline int cal(string x,string y){
	int L=(int)x.size();
	int l=-1,r=0;
	for(int i=0;i<L;i++)
	{
		if(x[i]^y[i]){
			if(!~l){
				l=i;
			}
			r=i;
		}
	}
	ull hx=0,hy=0;
	for(int i=l;i<=r;i++)
	{
		hx=hx*seed+(x[i]-'a'+1);
		hy=hy*seed+(y[i]-'a'+1);
	}
	pair <ull,ull> cur=pair<ull,ull>(hx,hy);
	if(tb.find(cur)!=tb.end()){
		return tb[cur];
	}
	else{
		idx++;
		tb[cur]=idx;
		return idx;
	}
}
const int MAXS=5e6+10;
#define pii pair<int,int>
struct trie{
	int idx=1,dfc=0;
	int tr[MAXS][26];
	int l[MAXS],r[MAXS];
	inline void clr(){
		for(int i=1;i<=idx;i++)
		{
			memset(tr[i],0,sizeof(tr[i]));
			l[i]=0;
			r[i]=0;
		}
		idx=1;
	}
	inline void ins(string s){
		int x=1;
		for(char c:s)
		{
			c-='a';
			if(!tr[x][c]){
				idx++;
				tr[x][c]=idx;
			}
			x=tr[x][c];
		}
	}
	void dfs(int x){
		dfc++;
		l[x]=dfc;
		for(int i=0;i<26;i++)
		{
			if(tr[x][i]){
				dfs(tr[x][i]);
			}
		}
		r[x]=dfc;
	}
	inline pii qry(string s){
		int x=1;
		for(char c:s)
		{
			c-='a';
			if(!tr[x][c]){
				break;
			}
			x=tr[x][c];
		}
		return pii(l[x],r[x]);
	}
}tr[2];
inline string rev(string x){
	reverse(x.begin(),x.end());
	return x;
}
inline void ins(string x,string y){
	int L=(int)x.size();
	int l=-1,r=0;
	for(int i=0;i<L;i++)
	{
		if(x[i]^y[i]){
			if(!~l){
				l=i;
			}
			r=i;
		}
	}
	tr[0].ins(rev(x.substr(0,l)));
	tr[1].ins(y.substr(r+1,L-r-1));
}
#define tii tuple <int,int,int>
vector <tii> mdf[MAXS];
vector <pii> qry[MAXS];
namespace BIT{
	int L;
	int tr[MAXS];
	#define lowbit(x) x&-x
	inline void clr(int x){
		L=x;
		memset(tr,0,sizeof(int)*(L+1));
	}
	inline void mdf(int l,int r,int v){
		l--;
		while(r>l)
		{
			tr[r]+=v;
			r^=lowbit(r);
		}
		while(l>r)
		{
			tr[l]-=v;
			l^=lowbit(l);
		}
	}
	inline int qry(int p){
		int res=0;
		for(int i=p;i<=L;i+=lowbit(i))
		{
			res+=tr[i];
		}
		return res;
	}
}
inline void ins_mdf(string x,string y){
	int L=(int)x.size();
	int l=-1,r=0;
	for(int i=0;i<L;i++)
	{
		if(x[i]^y[i]){
			if(!~l){
				l=i;
			}
			r=i;
		}
	}
	pii cur=tr[0].qry(rev(x.substr(0,l)));
	int pl=cur.first,pr=cur.second;
	pii cov=tr[1].qry(y.substr(r+1,L-r-1));
	int ql=cov.first,qr=cov.second;
	mdf[pl].push_back(tii(ql,qr,1));
	mdf[pr+1].push_back(tii(ql,qr,-1));
}
inline void ins_qry(string x,string y,int id){
	int L=(int)x.size();
	int l=-1,r=0;
	for(int i=0;i<L;i++)
	{
		if(x[i]^y[i]){
			if(!~l){
				l=i;
			}
			r=i;
		}
	}
	int p=tr[0].qry(rev(x.substr(0,l))).first;
	int q=tr[1].qry(y.substr(r+1,L-r-1)).first;
	qry[p].push_back(pii(q,id));
}
inline void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i][0] >> s[i][1];
		if(s[i][0]==s[i][1]){
			continue;
		}
		S[cal(s[i][0],s[i][1])].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		cin >> t[i][0] >> t[i][1];
		if(t[i][0].size()!=t[i][1].size()){
			continue;
		}
		T[cal(t[i][0],t[i][1])].push_back(i);
	}
	for(int i=1;i<=idx;i++)
	{
		if(S[i].empty()||T[i].empty()){
			continue;
		}
		tr[0].clr();
		tr[1].clr();
		for(int x:S[i])
		{
			ins(s[x][0],s[x][1]);
		}
		tr[0].dfc=0;
		tr[1].dfc=0;
		tr[0].dfs(1);
		tr[1].dfs(1);
		for(int i=1;i<=tr[0].dfc;i++)
		{
			mdf[i].clear();
			qry[i].clear();
		}
		for(int x:S[i])
		{
			ins_mdf(s[x][0],s[x][1]);
		}
		for(int x:T[i])
		{
			ins_qry(t[x][0],t[x][1],x);
		}
		BIT::clr(tr[1].dfc);
		for(int i=1;i<=tr[0].dfc;i++)
		{
			for(tii cur:mdf[i])
			{
				int l=get<0>(cur),r=get<1>(cur),v=get<2>(cur);
				BIT::mdf(l,r,v);
			}
			for(pii cur:qry[i])
			{
				int p=get<0>(cur),id=get<1>(cur);
				ans[id]=BIT::qry(p);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << '\n';
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#ifdef LOCAL
	atexit([](){fprintf(stderr,"%.3lfs\n",(double)clock()/CLOCKS_PER_SEC);});
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}