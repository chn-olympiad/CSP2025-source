#include<bits/stdc++.h>
using namespace std;

#define int long long 
//#define double long double
#define me(x,v) memset(x,v,sizeof(x))
#define siz(x) ((int)(x).size())
#define x first
#define y second
#define L(i,l,r) for(int i=(l);i<=(r);i++)
#define R(i,r,l) for(int i=(r);i>=(l);i--) 
#define wr(...) printf(__VA_ARGS__)
#define p(x,y) pair<x,y>
#define ve(x) vector<x>

#ifdef DGR
#define dwr(...) printf(__VA_ARGS__)
#define ast(expr) assert(expr)
#else
#define dwr
#define ast
#endif

#define el "\n"

char gc(){
	return (char)getchar(); 
} 
void pc(char c){
	putchar(c);
}
int rd(){
	int sgn=0,ret=0,c=gc();
	while(c<'0'||c>'9'){
		sgn|=(c=='-');
		c=gc();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=gc();
	}
	return sgn?-ret:ret;
}

constexpr int N=1e6+7;

int n;
int a[N][4];

ve(int) hs[4];
int at[N];

void task(){
	n=rd();ast(n%2==0);
	
	L(i,1,3){
		hs[i].clear();	
	}
	
	int ans=0;
	L(i,1,n){
		int t=1;
		L(j,1,3){
			a[i][j]=rd();
			if(a[i][j]>a[i][t]){
				t=j;
			}
		}
		at[i]=t;
		ans+=a[i][t];
		hs[t].push_back(i);
	}
	
	static int st[4]={0,1,2,3};
	sort(st+1,st+1+3,[](int x,int y){
		return siz(hs[x])>siz(hs[y]);
	});
	int f1=st[1];
//	f2=st[2],f3=st[3];
	if(siz(hs[f1])>n/2){
		auto sec=[&](int x){
			int ret=0;
			L(j,1,3){
				if(j!=at[x]&&a[x][j]>ret){
					ret=a[x][j];
				}
			}
			return ret;
		};
//		L(i,0,siz(hs[f1])-1){
//			dwr("first %lld\n",hs[f1][i]);
//		}
		sort(hs[f1].begin(),hs[f1].end(),[&](int x,int y){
			return a[x][at[x]]-sec(x)<a[y][at[y]]-sec(y);
		});
		int tl=siz(hs[f1])-n/2;
		L(i,0,tl-1){
			int x=hs[f1][i];
//			dwr("remove %lld\n",x);
			ans+=sec(x)-a[x][at[x]];
		}
	}
	wr("%lld\n",ans);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T=rd();
	while(T--){
		task();	
	}	
}
