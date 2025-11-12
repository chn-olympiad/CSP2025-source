#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define _ll __int128
#define ull unsigned long long
template<typename T>inline void chkmin(T &x,T y){(x>y)&&(x=y);}
template<typename T>inline void chkmax(T &x,T y){(x<y)&&(x=y);}
namespace IO{
	bool Isdigit(char c){return c>='0'&&c<='9';}
	template<typename T>inline void read(T &x){
		x=0;char c=getchar();bool f=1;
		while(!Isdigit(c)){if(c=='-')f=0;c=getchar();}
		while(Isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
		x=f?x:-x;
	}
	template<typename T,typename ...Args>
	inline void read(T &x,Args &...args){read(x),read(args...);}
	int STK[110],TOP;
	inline void Write(int x){if(x==0)return putchar('0'),void();if(x<0)putchar('-'),x=-x;TOP=0;while(x)STK[++TOP]=x%10,x/=10;while(TOP)putchar(STK[TOP--]^48);}
	inline void Write(ll x){if(x==0)return putchar('0'),void();if(x<0)putchar('-'),x=-x;TOP=0;while(x)STK[++TOP]=x%10,x/=10;while(TOP)putchar(STK[TOP--]^48);}
	inline void Write(ull x){if(x==0)return putchar('0'),void();if(x<0)putchar('-'),x=-x;TOP=0;while(x)STK[++TOP]=x%10,x/=10;while(TOP)putchar(STK[TOP--]^48);}
	inline void Write(_ll x){if(x==0)return putchar('0'),void();if(x<0)putchar('-'),x=-x;TOP=0;while(x)STK[++TOP]=x%10,x/=10;while(TOP)putchar(STK[TOP--]^48);}
	inline void Write(unsigned x){if(x==0)return putchar('0'),void();if(x<0)putchar('-'),x=-x;TOP=0;while(x)STK[++TOP]=x%10,x/=10;while(TOP)putchar(STK[TOP--]^48);}
	inline void Write(char c){putchar(c);}
	inline void Write(const char *c){while(*c)putchar(*c++);}
	template<typename T,typename ...Args>
	inline void Write(T x,Args ...args){Write(x),Write(args...);}
}
using namespace IO;
const ll Inf=1e18;
const int N=1e4+10,M=1e6+10;
struct Edge{
	int u,v,w;
	inline Edge(int _u=0,int _v=0,int _w=0):
		u(_u),v(_v),w(_w){}
	inline friend bool operator<(Edge x,Edge y){return x.w<y.w;}
}PE[M],G[N],A[15][N],E[N*11],Tmp[N*11];
int n,m,K,Num,cnt,Cost[15],fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void Init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
ll Calc(int S){
	Num=n-1,cnt=n-1;
	for(int i=1;i<=cnt;i++)E[i]=G[i];
	for(int i=1;i<=K;i++)
		if(S>>(i-1)&1){
			int Cnt=0;
			for(int x=1,y=1;x<=cnt||y<=n;){
				if(y>n)Tmp[++Cnt]=E[x++];
				else if(x>cnt)Tmp[++Cnt]=A[i][y++];
				else Tmp[++Cnt]=E[x].w<A[i][y].w?E[x++]:A[i][y++];
			}
			cnt=Cnt,Num++;
			for(int j=1;j<=cnt;j++)E[j]=Tmp[j];
		}
	Init(n+K);
	ll Res=0;
	for(int i=1;i<=cnt;i++){
		int u=find(E[i].u);
		int v=find(E[i].v);
		if(u==v)continue;
		Res+=E[i].w;
		fa[u]=v;
		if(!--Num)break;
	}
	return Res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n,m,K);
	for(int i=1,u,v,w;i<=m;i++)
		read(u,v,w),PE[i]=Edge(u,v,w);
	Init(n),sort(PE+1,PE+m+1);
	for(int i=1;i<=m;i++){
		int u=find(PE[i].u);
		int v=find(PE[i].v);
		if(u==v)continue;
		fa[u]=v;
		G[++cnt]=PE[i];
		if(cnt==n-1)break;
	}
	for(int i=1;i<=K;i++){
		read(Cost[i]);
		for(int j=1,w;j<=n;j++){
			read(w);
			A[i][j]=Edge(j,n+i,w);
		}
		sort(A[i]+1,A[i]+n+1);
	}
	ll Res=Inf;
	for(int S=0;S<(1<<K);S++){
		ll Sum=0;
		for(int i=1;i<=K;i++)
			if(S>>(i-1)&1)
				Sum+=Cost[i];
		chkmin(Res,Sum+Calc(S));
	}
	Write(Res,'\n');
}