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
	#define ppc(x) __builtin_popcount(x)
	const int mod=998244353;
	const int inf=0x3f3f3f3f;
	const int Max=500+10;
	int n,m; int c[Max];
	int f[20][us(18)];
	string s;
	il void _start() {cin>>n>>m; cin>>s; }
	il void _() {
		s=" "+s;
		O(i,1,n) cin>>c[i];
		f[0][0]=1;
		O(S,0,us(n)-1) O(i,1,n) if(!has(S,i-1)) O(j,0,n) {
			int x=j+(ppc(S)-j<c[i]&&s[ppc(S)+1]=='1');
			f[x][S|us(i-1)]=(f[x][S|us(i-1)]+f[j][S])%mod;
		}
		int ans=0; 
		O(j,m,n) ans=(ans+f[j][us(n)-1])%mod;
		cout<<ans<<'\n';
	}
}
bool edM;
signed main() {
#ifndef FastIO
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	O(i,1,Tnum) {_::_start(); _::_(); }
	return 0;
}

/*
g++ "employ.cpp" -o "employ.exe" -std=c++14 "-Wl,--stack=1000000000" -Wall -Wextra; if($?) {.\"employ.exe" }
*/