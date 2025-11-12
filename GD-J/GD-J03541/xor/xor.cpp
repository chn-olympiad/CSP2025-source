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

const int MAXN=5e5+5;
int n,k;
int a[MAXN];
int s[MAXN];
//int c[MAXN][25];
//int s[MAXN][25];
//int t[25],len;
//#define calc(l,r,pos) (s[r][pos]^s[l-1][pos])

//map<pair<int,int>,int> mp;
vector<pair<int,int> > ans;

//void work(int id){
//	int tar=t[id];
//	
//}

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	if(a.second==b.second) return a.first>b.first;
	return a.second<b.second;
}

void solve(){
	tin>>n>>k;
	For(i,1,n) tin>>a[i];
	For(i,1,n) s[i]=s[i-1]^a[i];
	For(len,1,n){
		For(i,1,n-len+1){
			int j=i+len-1;
			int t=s[j]^s[i-1];
			if(t==k) ans.push_back(make_pair(i,j));
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	int cnt=0,l=0,r=0;
	For(i,0,(int)ans.size()-1){
		if(ans[i].first>r){
			++cnt;
			r=ans[i].second;
		}
	}
	tout<<cnt<<'\n';
//	For(i,1,20) t[i]=k&1,k>>=1;
	
//	For(j,1,n)
//		For(i,1,20){
//			c[j][i]=a[j]&1,a[j]>>=1;
//		}
	
//	For(i,1,20)
//		For(j,1,n){
//			s[j][i]=s[j-1][i]^c[j][i];
//		}
		
//	For(i,1,20){
//		work(i);
//	}
}

#define thlog5
signed main(){
	#ifdef thlog5
		#define TimuMingzi "xor"
		freopen(TimuMingzi".in","r",stdin);
		freopen(TimuMingzi".out","w",stdout);
	#endif
	solve();
	return 0;
}

