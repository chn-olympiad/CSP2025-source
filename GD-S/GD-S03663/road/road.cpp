#include<bits/stdc++.h>
using namespace std;bool Mbe;
const int IN=3.5e7;
char _i[IN],*_I=_i;
inline int rd(){
	for(;*_I<0x30;_I++);int x=0;
	for(;*_I>0x2f;_I++)x=(x<<1)+(x<<3)+(*_I^0x30);return x;
}
namespace MAOJUN{

typedef long long ll;
const int N=1e4+5,M=1e6+5,K=10;
int n,m,k,c[K];

struct nd{
	int u,v,w;nd(){}
	nd(int u,int v,int w):u(u),v(v),w(w){}
	bool operator<(const nd&b)const{return w<b.w;}
}A[1<<K][N+K],B[M],C[K][N];
int fa[N+K],sz[1<<K];
inline void bld(){iota(fa+1,fa+n+k+1,1);}
inline int fd(int x){for(;x^fa[x];x=fa[x]=fa[fa[x]]);return x;}
inline bool ck(int x,int y){x=fd(x);y=fd(y);if(x==y)return 0;fa[x]=y;return 1;}
inline void main(){
	n=rd();m=rd();k=rd();
	for(int i=1;i<=m;i++){B[i].u=rd();B[i].v=rd();B[i].w=rd();}
	sort(B+1,B+m+1);bld();int z=0;
	for(int i=1;i<=m;i++)if(ck(B[i].u,B[i].v))A[0][++z]=B[i];
	for(int i=0;i<k;i++){
		c[i]=rd();
		for(int j=1;j<=n;j++)C[i][j]=nd(j,n+1+i,rd());
		sort(C[i]+1,C[i]+n+1);
	}
	sz[0]=n-1;
	for(int s=1;s<1<<k;s++){
		int p=__builtin_ctz(s),z=sz[s&s-1];
		for(int i=1;i<=z;i++)B[i]=A[s&s-1][i];
		for(int i=1;i<=n;i++)B[z+i]=C[p][i];
		inplace_merge(B+1,B+z+1,B+z+n+1);bld();
		for(int i=1;i<=z+n;i++)if(ck(B[i].u,B[i].v))A[s][++sz[s]]=B[i];
	}
	ll as=1e18;
	for(int s=0;s<1<<k;s++){
		ll sum=0;
		for(int i=0;i<k;i++)if(s>>i&1)sum+=c[i];
		for(int i=1;i<=sz[s];i++)sum+=A[s][i].w;
		as=min(as,sum);
	}
	printf("%lld\n",as);
}

}bool Med;int main(){
#ifdef IO
	freopen("B/road1.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
#ifdef TM
	atexit([]{fprintf(stderr,"%.lfms\n%lfMB\n",clock()*1000./CLOCKS_PER_SEC,(&Mbe-&Med)/1024./1024);});
#else
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	fread(_i,1,IN,stdin);
	MAOJUN::main();
	return 0;
}