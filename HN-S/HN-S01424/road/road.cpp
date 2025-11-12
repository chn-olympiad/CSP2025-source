#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<time.h>
#include<queue>
#include<set>
#include<unordered_map>
#include<bitset>
#include<random>
#define ci const int
#define iv inline void
#define ic inline ci
#define ll long long
#define ull unsigned ll
#define int ll
#define gc getchar_unlocked
#define pc putchar
ic re();iv pr(ci x);iv prs(ci x);iv prn(ci x);
iv swp(int&a,int&b){a^=b^=a^=b;}
ic Max(ci a,ci b){return a>b?a:b;}
ic Min(ci a,ci b){return a<b?a:b;}
iv gma(int&a,ci b){a=Max(a,b);}
iv gmi(int&a,ci b){a=Min(a,b);}
ic Abs(ci a){return a<0?-a:a;}
#define M 1000003
#define N 10003
int n,m,k,fa[N+20],val[11][N];
struct edg{
	int u,v,w;
	edg(ci a=0,ci b=0,ci c=0){u=a,v=b,w=c;}
	bool operator<(const edg x)const{return w<x.w;}
}e[M+10*N],eoe[M+10*N];
ic fnd(ci u){return u==fa[u]?u:fa[u]=fnd(fa[u]);}
iv wkbf(){
	for(int i=1;i<=n;++i)fa[i]=i;
	std::sort(e+1,e+m+1);
	int ans=0;
	for(int i=1;i<=m;++i){
		if(fnd(e[i].u)!=fnd(e[i].v)){
			fa[fnd(e[i].v)]=fnd(e[i].u);
			ans+=e[i].w;
		}
	}prn(ans);
}
iv wkspA(){
	for(int i=1;i<=n+k;++i)fa[i]=i;
	int tp=m;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
			e[++tp]=edg(n+i,j,val[i][j]);
	std::sort(e+1,e+tp+1);
	int ans=0;
	for(int i=1;i<=tp;++i){
		if(fnd(e[i].u)!=fnd(e[i].v)){
			fa[fnd(e[i].v)]=fnd(e[i].u);
			ans+=e[i].w;
		}
	}prn(ans);
}
iv wk(){
	int KK=1<<k;
	int ttans=0x7fff7fff7fff7fffll;
	for(int i=1;i<=n;++i)fa[i]=i;
	std::sort(e+1,e+m+1);
	int tpm=0;
	for(int i=1;i<=m;++i){
		if(fnd(e[i].u)!=fnd(e[i].v)){
			fa[fnd(e[i].v)]=fnd(e[i].u);
			eoe[++tpm]=e[i];
		}
	}
	for(int I=0;I<KK;++I){
		for(int i=1;i<=n+10;++i)fa[i]=i;
		for(int i=1;i<=tpm;++i)e[i]=eoe[i];
		int tp=tpm;
		int ans=0;
		for(int i=1;i<=k;++i)
			if((I>>i-1)&1){
				ans+=val[i][0];
				for(int j=1;j<=n;++j)
					e[++tp]=edg(n+i,j,val[i][j]);
			}
		std::sort(e+1,e+tp+1);
		for(int i=1;i<=tp;++i){
			if(fnd(e[i].u)!=fnd(e[i].v)){
				fa[fnd(e[i].v)]=fnd(e[i].u);
				ans+=e[i].w;
			}
		}gmi(ttans,ans);
		//prs(I),prn(ans);
	}prn(ttans);
}
iv work(){
	n=re(),m=re(),k=re();
	for(int i=1,a,b,c;i<=m;++i)
		a=re(),b=re(),c=re(),
		e[i]=edg(a,b,c);
	if(!k)return wkbf();
	bool spjA=1,spjA1;
	for(int i=1;i<=k;++i){
		val[i][0]=re();
		spjA&=!val[i][0];
		spjA1=0;
		for(int j=1;j<=n;++j)
			val[i][j]=re(),
			spjA1|=!val[i][j];
		spjA&=spjA1;
	}if(spjA)return wkspA();
	wk();
}
/*
ulimit -s 10240
10 MB

41 min
12/25

-24 min
14/25
*/
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int T=1||re();T--;)work();
}
ic re(){
	int x=0;char c=gc(),f=0;
	while(c<48||c>57)f|=(c=='-'),c=gc();
	while(c<58&&c>47)x=x*10+(c^48),c=gc();
	return f?-x:x;
}
void pri(ci x){if(x>9)pri(x/10);pc(x%10^48);}
iv pr(ci x){if(x<0)pc('-'),pri(-x);else pri(x);}
iv prs(ci x){pr(x),pc(32);}
iv prn(ci x){pr(x),pc(10);}
/*
g++ -Wall -Wextra -O2 1.cpp -o 1
Ren5Jie4Di4Ling5%
*/
