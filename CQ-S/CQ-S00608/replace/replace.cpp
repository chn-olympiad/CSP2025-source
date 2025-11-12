#include<bits/stdc++.h>
using namespace std;
// #define FastIO
#define fi first
#define se second
#define il inline
#define ep emplace
#define eb emplace_back
#define us(n) (1ll<<(n))
#define has(S,i) ((S)>>(i)&1)
#define O(i,l,r) for(int i=(l);i<=(r);++i)
#define U(i,r,l) for(int i=(r);i>=(l);--i)
using ll=long long; using ull=unsigned ll;
template<typename T> il T& omax(T& a,T b) {return a=max(a,b); }
template<typename T> il T& omin(T& a,T b) {return a=min(a,b); }
bool bgM;
int Tid=0,Tnum=1;
#ifdef FastIO
struct IO {
	#define IOSIZE us(20)
	char I[IOSIZE],*p1=I,*p2=I,O[IOSIZE],*q=O;
	~IO() {fwrite(O,1,q-O,stdout); }
	il char gc() {return (p1==p2&&(p2=(p1=I)+fread(I,1,IOSIZE,stdin),p1==p2))?EOF:*p1++; }
	il void pc(char c) {if(q-O==IOSIZE) fwrite(O,1,IOSIZE,stdout),q=O; *q++=c; }
	il void read(auto &x) {
		int f=1; char c; x=0;
		while(c=gc(),c<'0'||c>'9') if(c=='-') f=-1;
		while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=gc();
		x*=f;
	}
	il void write(auto x) {
		int d[40],t=0; if(x<0) pc('-'),x=-x;
		do d[t++]=x%10; while(x/=10);
		while(t--) pc(d[t]+'0');
	}
	IO& operator >> (auto &x) {read(x); return *this; }
	IO& operator >> (string &x) {
		char c;
		while(c=gc(),c<'a'||c>='z');
		while(c>='a'&&c<='z') x+=c,c=gc();
		return *this;
	}
	IO& operator << (auto x) {write(x); return *this; }
	IO& operator << (char c) {pc(c); return *this; }
	IO& operator << (const char *s) {while(*s) pc(*s++); return *this; }
} io;
#define cin io
#define cout io
#endif
namespace _ {
	#define lb(x) ((x)&-(x))
	#define dr(x) ((x)&=(x)-1)
	#define ctz(x) __builtin_ctz(x)
	const int inf=0x3f3f3f3f;
	const int Max=2e5+10;
	const int Cax=5e6+10;
	int n,q;
	string s[Max][2];
	string t[Max][2];
	struct Tree {
		int ch[Cax][26];
		int to[Cax];
		int n;
		il int gos(int p,char c) {if(!ch[p][c-'a']) ch[p][c-'a']=++n,to[p]|=us(c-'a'); return ch[p][c-'a']; }
		il int got(int p,char c) {if(!ch[p][c-'a']) return -1; return ch[p][c-'a']; }
		il void init() {
			O(i,0,n) while(to[i]) ch[i][ctz(to[i])]=0,dr(to[i]);
			n=0; 
		}
	} L,R;
	int bit[Cax];
	il void add(int p,int x) {for(;p<=R.n+1;p+=lb(p)) bit[p]+=x; }
	il int sum(int p) {int x=0; for(;p;dr(p)) x+=bit[p]; return x; }
	vector<int> pos[Cax]; // 左树对应的右树的pos
	vector<pair<int,int> > Q[Cax]; // 左树的查询
	int dfn[Cax],ldf[Cax],D; // 右树
	il void dfs1(int u) {
		dfn[u]=++D; int T=R.to[u];
		while(T) {int v=R.ch[u][ctz(T)]; dfs1(v); dr(T); }
		ldf[u]=D;
	}
	int ans[Max];
	il void dfs2(int u) {
		for(auto x:pos[u]) add(dfn[x],1),add(ldf[x]+1,-1); //,cout<<x<<' '<<dfn[x]<<' '<<ldf[x]<<"  ";
		for(auto x:Q[u]) ans[x.se]=sum(dfn[x.fi]); //,cout<<"p"<<dfn[x.fi]<<"p\n";
		int T=L.to[u];
		while(T) {int v=L.ch[u][ctz(T)]; dfs2(v); dr(T); }
		for(auto x:pos[u]) add(dfn[x],-1),add(ldf[x]+1,1);
	}
	int pres[Max],sufs[Max],lens[Max]; int pret[Max],suft[Max],lent[Max];
	const int Hmod[2]={(int)(1e9+7),998244353},base=101;
	struct Ha {
		int val[2];
		Ha() {val[0]=val[1]=0; }
		Ha(int a,int b) {val[0]=a; val[1]=b; }
		il Ha operator * (Ha a) {
			return {int((ll)val[0]*a.val[0]%Hmod[0]),int((ll)val[1]*a.val[1]%Hmod[1])}; }
		il Ha operator + (Ha a) {
			return {(val[0]+a.val[0])%Hmod[0],(val[1]+a.val[1])%Hmod[1]}; }
		il bool operator == (Ha a) {
			return val[0]==a.val[0]&&val[1]==a.val[1]; }
		il bool operator < (Ha a) {
			return val[0]==a.val[0]?val[1]<a.val[1]:val[0]<a.val[0]; }
		il void print() {cout<<"("<<val[0]<<' '<<val[1]<<") ";}
	} ;
	vector<pair<Ha,Ha> > lsh;
	il void calc(int &pre,int &suf,pair<Ha,Ha> &h,string s[2],int len) {
		O(j,1,len) if(s[0][j]!=s[1][j]) {pre=j-1; break; }
		U(j,len,1) if(s[0][j]!=s[1][j]) {suf=j+1; break; }
		Ha x[2]; O(b,0,1) O(j,pre+1,suf-1) x[b]=(x[b]*Ha(base,base))+Ha(s[b][j]-'a',s[b][j]-'a');
		h={x[0],x[1]};
	}
	pair<Ha,Ha> Hs[Max],Ht[Max];
	vector<int> S[Max],T[Max];
	il void _start() {
		cin>>n>>q;
		O(i,1,n) cin>>s[i][0]>>s[i][1];
		O(i,1,q) cin>>t[i][0]>>t[i][1];
	}
	il void _() {
		O(i,1,n) if(s[i][0]!=s[i][1]) {
			lens[i]=s[i][0].size(); s[i][0]=" "+s[i][0]; s[i][1]=" "+s[i][1]; calc(pres[i],sufs[i],Hs[i],s[i],lens[i]); lsh.eb(Hs[i]); 
			// Hs[i].fi.print(); cout<<'\n'; 
			}
		O(i,1,q) if(t[i][0].size()==t[i][1].size()) {
			lent[i]=t[i][0].size(); t[i][0]=" "+t[i][0]; t[i][1]=" "+t[i][1]; calc(pret[i],suft[i],Ht[i],t[i],lent[i]); lsh.eb(Ht[i]); 
			// Ht[i].fi.print(); cout<<'\n';
			}
		auto cmp=[](pair<Ha,Ha> a,pair<Ha,Ha> b) {return a.fi==b.fi?a.se<b.se:a.fi<b.fi; };
		sort(lsh.begin(),lsh.end(),cmp);
		lsh.erase(unique(lsh.begin(),lsh.end(),[](pair<Ha,Ha> a,pair<Ha,Ha> b) {return a.fi==b.fi&&a.se==b.se; }),lsh.end());
		O(i,1,n) if(s[i][0]!=s[i][1]) {int p=lower_bound(lsh.begin(),lsh.end(),Hs[i],cmp)-lsh.begin(); S[p].eb(i); }
		O(i,1,q) if(t[i][0].size()==t[i][1].size()) {int p=lower_bound(lsh.begin(),lsh.end(),Ht[i],cmp)-lsh.begin(); T[p].eb(i); }
		O(i,0,(int)lsh.size()-1) {
			O(j,0,L.n) pos[j].clear(),Q[j].clear();
			D=0; O(j,0,R.n) dfn[j]=ldf[j]=0; 
			L.init(); R.init();
			// cout<<"S: ";
			for(auto x:S[i]) {
				// cout<<x<<' ';
				int r=0; O(i,sufs[x],lens[x]) r=R.gos(r,s[x][0][i]);
				int l=0; U(i,pres[x],1) l=L.gos(l,s[x][0][i]);
				pos[l].eb(r);
				// cout<<l<<' '<<r<<"  ";
			}
			// cout<<'\n';
			// cout<<"T: ";
			for(auto x:T[i]) {
				// cout<<x<<' ';
				int r=0; O(i,suft[x],lent[x]) {int tmp=R.got(r,t[x][0][i]); if(tmp==-1) break; r=tmp; }
				int l=0; U(i,pret[x],1) {int tmp=L.got(l,t[x][0][i]); if(tmp==-1) break; l=tmp; }
				Q[l].eb(r,x);
				// cout<<l<<' '<<r<<"  ";
			}
			// cout<<'\n';
			dfs1(0);
			dfs2(0);
		}
		O(i,1,q) cout<<ans[i]<<'\n';
	}
}
bool edM;
signed main() {
#ifndef FastIO
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	O(i,1,Tnum) {_::_start(); _::_(); }
	return 0;
}

/*
g++ "replace.cpp" -o "replace.exe" -std=c++14 "-Wl,--stack=1000000000" -Wall -Wextra; if($?) {.\"replace.exe" }
*/