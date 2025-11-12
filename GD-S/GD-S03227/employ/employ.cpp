#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL
#define For(i,t,n) for(int i=t;i<=n;++i)
#define foR(i,t,n) for(int i=t;i>=n;--i)

namespace th666{
	struct input{
		#define gc getchar
		template<typename T>
		void read(T &x){
			x=0; signed f=1,ch=gc();
			while(ch<48||ch>57){
				if(ch==EOF) return;
				if(ch==45) f=-1;
				ch=gc();
			}
			while(ch>=48&&ch<=57){
				if(ch==EOF) break;
				x=(x<<3)+(x<<1)+(ch^48);
				ch=gc();
			}
			x*=f;
		}
		template<typename T>
		input& operator>>(T &x){
			read(x); return (*this);
		}
		#undef gc
	}tin;
	struct output{
		template<typename T>
		void write(T x){
			signed stk[55],top=0;
			if(x<0) x=-x,putchar(45);
			do{stk[++top]=x%10;x/=10;}while(x);
			while(top){putchar(stk[top--]|48);}
		}
		template<typename T>
		void write(T *x){
			while(*x) putchar(*(x++));
		}
		void write(const char&x){
			putchar(x);
		}
		template<typename T>
		output& operator<<(const T&x){
			write(x); return(*this);
		}
	}tout;
};
using th666::tin;
using th666::tout;

const int MAXN=505;
const int MOD=998244353;
int n,m,ans;
char s[MAXN];
int p[MAXN],c[MAXN];
bitset<MAXN> vis;

void check(){
	int yes1=0,no1=0;
	For(i,1,n){
//		cerr<<p[i]<<' ';
		if(s[i]=='0'||no1>=c[p[i]]) no1++;
		else{
			++yes1;
			if(yes1==m){
				++ans;
				if(ans==MOD) ans=0;
				return;
			}
		}
	}
//	cerr<<'\n'; 
}

void dfs(int k){
	if(k==n+1){
		check();
		return;
	}
	For(i,1,n){
		if(vis[i]) continue;
		vis[i]=1; p[k]=i;
		dfs(k+1);
		vis[i]=0;
	}
}

void solve(){
	tin>>n>>m;
	cin>>(s+1);
//hyw? 1 : 0 ;
//	bool all1=1;
//	For(i,0,n-1) all1&=(s[i]=='1');
//	cerr<<all1;
//	if(all1){
//		LL fac=1;
//		For(i,1,n) fac=fac*i%MOD;
//		tout<<fac<<'\n';
//		return;
//	}
	For(i,1,n) tin>>c[i];
	dfs(1);
	tout<<ans;
}
#define thlog5
signed main(){
	//rp=0
#ifdef thlog5
	#define TimuMingzi "employ"
	freopen(TimuMingzi".in","r",stdin);
	freopen(TimuMingzi".out","w",stdout);
#endif
	solve();
	return 0;
}

