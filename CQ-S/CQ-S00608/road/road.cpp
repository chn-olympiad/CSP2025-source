#include<bits/stdc++.h>
using namespace std;
#define FastIO
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
	char I[IOSIZE+10],*p1=I,*p2=I,O[IOSIZE+10],*q=O;
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
	IO& operator << (auto x) {write(x); return *this; }
	IO& operator << (char c) {pc(c); return *this; }
	IO& operator << (const char *s) {while(*s) pc(*s++); return *this; }
} io;
#define cin io
#define cout io
#endif
namespace _ {
	const int inf=0x3f3f3f3f;
	const int Max=1e4+10+10;
	int n,m,k;
	struct edge {int u,v,w; } E[1000010],tmp[1000010];
	int C[20],val[15][Max];
	int dsu[Max],sz[Max];
	vector<int> lsh;
	il void init(int n) {O(i,1,n) dsu[i]=i,sz[i]=1; }
	il int get_dsu(int x) {return x==dsu[x]?x:dsu[x]=get_dsu(dsu[x]); }
	il bool merge(int u,int v) {
		u=get_dsu(u); v=get_dsu(v);
		if(u!=v) return dsu[u]=v,sz[v]+=sz[u],1;
		return 0;
	}
	il void _start() {
		cin>>n>>m>>k;
		O(i,1,m) cin>>E[i].u>>E[i].v>>E[i].w;
		O(i,1,k) {
			cin>>C[i];
			O(j,1,n) cin>>val[i][j];
		}
	}
	il void _() {
		auto cmp=[](edge a,edge b) {return a.w<b.w; };
		sort(E+1,E+m+1,cmp);
		init(n); int nm=0; ll sum=0;
		O(i,1,m) if(merge(E[i].u,E[i].v)) E[++nm]=E[i],sum+=E[i].w;
		m=nm;
		O(i,1,n-1) tmp[i]=E[i];
		ll minn=sum;
		O(S,1,us(k)) {
			O(i,1,n-1) E[i]=tmp[i];
			int m=n-1,num=0;
			int cnt=0; ll ans=0;
			O(i,1,k) if(has(S,i-1)) {
				num++; ans+=C[i];
				O(j,1,n) E[++m]={i+n,j,val[i][j]};
			}
			sort(E+1,E+m+1,cmp); init(n+k);
			O(i,1,m) {
				if(merge(E[i].u,E[i].v)) {
					cnt++; ans+=E[i].w;
					if(cnt==n+num-1||ans>=minn) break; 
				}
			}
			omin(minn,ans);
		}
		cout<<minn<<'\n';
	}
}
bool edM;
signed main() {
#ifndef FastIO
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	O(i,1,Tnum) {_::_start(); _::_(); }
	return 0;
}

/*
g++ "road.cpp" -o "road.exe" -std=c++14 "-Wl,--stack=1000000000" -Wall -Wextra; if($?) {.\"road.exe" }
*/