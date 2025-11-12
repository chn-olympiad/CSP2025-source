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

const int MAXN=105;
int n,m;
int a[MAXN];
int seat[15][15];

void solve(){
	tin>>n>>m;
	For(i,1,n*m) tin>>a[i];
	int xiaoR=a[1];
	sort(a+1,a+n*m+1,greater<int>());
//	cerr<<"sorted\n";
	int rank=1;
	For(i,1,n*m){
		if(a[i]==xiaoR){
			rank=i;
			break;
		}
	}
//	cerr<<"found rank\n";
	int tot=0;
	For(i,1,m){
		if(i&1){
			For(j,1,n) seat[j][i]=++tot;
		}else{
			foR(j,n,1) seat[j][i]=++tot;
		}
	}
//	cerr<<"rank: "<<rank<<'\n';
	For(i,1,m){
		For(j,1,n){
//			cerr<<seat[j][i]<<' ';
			if(seat[j][i]==rank){
				tout<<i<<' '<<j<<'\n';
				return;
			}
		}
//		cerr<<'\n';
	}
}

#define thlog5
signed main(){
	#ifdef thlog5
		#define TimuMingzi "seat"
		freopen(TimuMingzi".in","r",stdin);
		freopen(TimuMingzi".out","w",stdout);
	#endif
	solve();
	return 0;
}

