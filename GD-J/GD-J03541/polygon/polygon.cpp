#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define int LL
#define For(i,t,n) for(int i=t;i<=n;++i)
#define foR(i,t,n) for(int i=t;i>=n;--i)

namespace th666{
	struct in666{
		#define gc getchar
		template<typename T>
			void read(T &x){
				x=0; signed f=1,ch=gc();
				while(ch<48||ch>57){
					if(ch==EOF) return;
					if(ch==45) f=-f;
					ch=gc();
				}
				while(ch>=48&&ch<=57){
					if(ch==EOF) break;
					x=(x<<3)+(x<<1)+(ch^48);
					ch=gc();
				}
				x*=f;
			}
		#undef gc
		template<typename T>
		in666& operator>>(T &x){
			read(x); return(*this);
		}
	}tin;
	struct out666{
		template<typename T>
		void write(T x){
			signed stk[55],top=0;
			if(x<0) putchar(45),x=-x;
			do{stk[++top]=x%10;x/=10;}while(x);
			while(top) putchar(stk[top--]|48);
		}
		template<typename T>
		void write(T *x){
			while(*x) putchar(*(x++));
		}
		void write(const char&x){
			putchar(x);
		}
		template<typename T>
		out666& operator<<(const T&x){
			write(x); return(*this);
		}
	}tout;
}
using th666::tin;
using th666::tout;

const int MAXN=5005;
int n,m,ans;
int a[MAXN];
int p[MAXN];
int s[MAXN];
int vis[MAXN];

void work(int r){
	int s1=0,s2=0;
	For(i,1,r){
		s1+=p[i];
		s2=max(s2,p[i]);
	}
	if(s1>2*s2) ++ans;
//	For(i,1,n) p[i]=vis[i]=0;
}

void dfs(int k,int r){
	if(k==r+1){
		work(r);
		return;
	}
	For(i,1,n){
		if(vis[i]) continue;
		vis[i]=1; p[i]=a[i];
		dfs(k+1,r);
		vis[i]=0;
	}
}

void solve(){
	tin>>n;
	For(i,1,n) tin>>a[i];
	For(i,3,n)dfs(1,i);
	tout<<ans;
}

//#define thlog5
signed main(){
	#ifdef thlog5
		#define TimuMingzi "polygon"
		freopen(TimuMingzi".in","r",stdin);
		freopen(TimuMingzi".out","w",stdout);
	#endif
	solve();
	return 0;
}

