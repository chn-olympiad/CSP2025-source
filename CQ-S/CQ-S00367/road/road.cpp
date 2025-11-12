#include <cstdio>
#include <algorithm>
#include <initializer_list>
int Ch;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){std::initializer_list<int>{(r(x),0)...};}
template<typename T>
void w(T x){
	if(9<x)w(x/10);
	putchar(x%10|48);
}
using ll=long long;
constexpr int N=10020,M=1000010,K=12;
ll ans,s;
int n,m,k,t,i,j,x,y,fa[N],S,T,c[K];
int find(const int x){return fa[x]!=x?fa[x]=find(fa[x]):x;}
struct ss{
	int x,y,k;
}e[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	r(n,m,k);
	for(i=1;i<=m;i++)r(e[i].x,e[i].y,e[i].k);
	std::sort(e+1,e+m+1,[](const ss&a,const ss&b){return a.k<b.k;});
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++){
		x=find(e[i].x);
		y=find(e[i].y);
		if(x==y)continue;
		fa[x]=y;
		e[++t]=e[i];
		s+=e[i].k;
		if(t==n-1)break;
	}
	ans=s;
	m=t;
	for(i=1;i<=k;i++){
		r(c[i]);
		t=1<<30;
		for(j=1;j<=n;j++){
			e[++m].x=n+i;
			e[m].y=j;
			r(e[m].k);
			t=std::min(e[m].k,t);
		}
		if(!c[i]&&!t)T|=1<<i-1;
	}
	std::sort(e+1,e+m+1,[](const ss&a,const ss&b){return a.k<b.k;});
	for(S=0;S<1<<K;S++){
		if((T&S)!=T)continue;
		s=0;
		for(i=1;i<=n+k;i++)fa[i]=i;
		for(i=1;i<=k;i++)if(S>>i-1&1)s+=c[i];
		t=n-1+__builtin_popcount(S);
		for(i=1;i<=m&&t&&s<ans;i++){
			if(e[i].x>n&&~S>>e[i].x-n-1&1)continue;
			x=find(e[i].x);
			y=find(e[i].y);
			if(x==y)continue;
			fa[x]=y;
			s+=e[i].k;
			t--;
		}
		ans=std::min(ans,s);
	}
	w(ans);
	return 0;
}