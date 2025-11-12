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
	IO& operator << (auto x) {write(x); return *this; }
	IO& operator << (char c) {pc(c); return *this; }
	IO& operator << (const char *s) {while(*s) pc(*s++); return *this; }
} io;
#define cin io
#define cout io
#endif
namespace _ {
	const int inf=0x3f3f3f3f;
	const int Max=1e5+10;
	int n,a[Max][3];
	vector<int> V[3];
	il void _start() {
		cin>>n;
		O(i,1,n) cin>>a[i][0]>>a[i][1]>>a[i][2];
		V[0].clear(); V[1].clear(); V[2].clear();
	}
	il void _() {
		int ans=0;
		O(i,1,n) {
			int x=-1,y=-1;
			O(j,0,2) if(x==-1||a[i][j]>a[i][x]) x=j;
			O(j,0,2) if(j!=x&&(y==-1||a[i][j]>a[i][y])) y=j;
			V[x].eb(a[i][x]-a[i][y]); ans+=a[i][x];
		}
		O(i,0,2) if(V[i].size()>n/2) {
			sort(V[i].begin(),V[i].end(),greater<int>());
			while(V[i].size()>n/2) ans-=V[i].back(),V[i].pop_back();
		}
		cout<<ans<<'\n';
	}
}
bool edM;
signed main() {
#ifndef FastIO
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>Tnum;
	O(i,1,Tnum) {_::_start(); _::_(); }
	return 0;
}

/*
g++ "club.cpp" -o "club.exe" -std=c++14 "-Wl,--stack=1000000000" -Wall -Wextra; if($?) {.\"club.exe" }
*/