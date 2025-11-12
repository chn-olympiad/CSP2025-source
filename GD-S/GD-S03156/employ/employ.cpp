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

constexpr int N=100;

int n,m;
int s[N],c[N],perm[N];

char st[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=rd(),m=rd();
scanf("%s",st+1);
L(i,1,n){
	s[i]=st[i]-'0';
}
L(i,1,n){
	dwr("%lld ",s[i]);
}
dwr(el);
	L(i,1,n){
		c[i]=rd();
	}
	
	int tot=1;
	L(i,1,n){
		perm[i]=i;
		tot*=i;
	} 
	
	int ans=0;
	L(i,1,tot){
		int sum=0;
		L(j,1,n){
			if(sum>=c[perm[j]]||!s[j]){
				sum++;
			}
		}
		if(n-sum>=m){
			ans++;
		}
		next_permutation(perm+1,perm+1+n);
	}
	
	wr("%lld\n",ans);
}
