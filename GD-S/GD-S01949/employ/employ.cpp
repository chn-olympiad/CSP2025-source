#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,k) for(int i=j;i<=k;++i)
#define g(i,j,k) for(int i=j;i>=k;--i)
int n,m,s,l;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;'0'>ch||ch>'9';ch=getchar())if(ch=='-')f=-f;
	for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	return x*f; 
}
void write(int x){if(x>9)write(x/10);putchar(x%10+48);}
const int N=555,mo=998244353;
inline void Add(int&x,int y){x=(x+y)%mo;}
inline int ksm(int x,int p=mo-2,int y=1){for(;p;p/=2,x=x*x%mo)if(p&1)y=x*y%mo;return y;}
int jc[N],ny[N];
inline int C(int n,int m){return(n<m||m<0)?0:jc[n]*ny[m]%mo*ny[n-m]%mo;}
inline void ycl(int n){
	jc[0]=1;
	f(i,1,n)jc[i]=jc[i-1]*i%mo;
	ny[n]=ksm(jc[n]);
	g(i,n,1)ny[i-1]=ny[i]*i%mo;
}
int c[N],d[N],f[N][N],g[N][N],F[N][N],G[N][N];char a[N];
inline void doing(){
	n=read();m=read();ycl(n);
	scanf("%s",a+1);
	f(i,1,n)++c[read()];d[0]=c[0];
	f(i,1,n)d[i]=d[i-1]+c[i];
	f(j,0,n)f(t,0,n)F[j][t]=C(j,t)*jc[t]%mo;
	f(k,0,n)f(t,0,n)G[k][t]=C(c[k+1],t);
	f[0][0]=1;
	f(i,1,n){
		f(j,0,n)f(k,0,n)if(l=f[j][k]){
			int r=min(c[k+1],j);
			if(a[i]^48)Add(g[j+1][k],l),l=l*(d[k]+j-s)%mo;
			f(t,0,r)Add(g[j-t][k+1],F[j][t]*G[k][t]%mo*l);
		}
		f(j,0,n)f(k,0,n)f[j][k]=g[j][k],g[j][k]=0;
		s+=a[i]^48;
	}
	f(j,0,n)f(k,n-m+1,n)f[j][k]=0;
	f(k,0,n)f(j,0,n)if(l=f[j][k]){
		int r=min(c[k+1],j);
		f(t,0,r)Add(f[j-t][k+1],F[j][t]*G[k][t]%mo*l);
	}
	write(jc[n-s]*f[0][n]%mo);putchar('\n');
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t=1;
	while(t--)doing();
} 
