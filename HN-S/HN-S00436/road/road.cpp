#include<bits/stdc++.h>
using namespace std;
#define def(X) constexpr int X=
#define LF putchar('\n')
#define SP putchar(' ')
#define int long long
def(oo) 1e16;
template<typename T>
inline void read(T& x){
	x=0;int f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=~f+1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x*=f;
}
template<typename T,typename... Args>
inline void read(T& x,Args&... args){
	read(x);
	read(args...);
}
template<typename T>
inline void write(T x){
	static int buf[40],top=0;
	if(x<0){x=-x;putchar('-');}
	while(x){buf[++top]=x%10,x/=10;}
	if(!top)buf[++top]=0;
	while(top)putchar(buf[top--]^48);
}
template<typename T,typename... Args>
inline void write(T x,Args... args){
	write(x);
	SP;
	write(args...);
}
def(N) 1e4+10;
def(M) 1e6+10;
def(K) 15;
int n,m,k;
struct node{
	int u,v,w;
}e[M<<1];
int a[K][N],vis[K];
int fa[N],val[N][K],c[K];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]); 
}
void merge(int u,int v){
	int fu=find(u),fv=find(v);
	if(fu==fv) return;
	for(int i=1;i<=k;++i)val[fv][i]=min(val[fv][i],val[fu][i]);
	fa[fu]=fv;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,u,v,w;
	read(n,m,k);
	for(i=1;i<=n;++i)fa[i]=i;
	for(i=1;i<=m;++i){
		read(e[i].u,e[i].v,e[i].w);
	}
	for(i=1;i<=k;++i){
		read(c[i]);
		for(j=1;j<=n;++j){
			read(a[i][j]);
			val[j][i]=a[i][j];
		}
	}
	sort(e+1,e+m+1,[](node x,node y){return x.w<y.w;});
	int tot=0,ans=0;
	for(i=1;i<=m;++i){
		u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		int res=oo,rt=0,vs=0;
		for(j=1;j<=k;++j){
			int t=(!vis[j])*c[j]+val[fu][j]+val[fv][j];
			if(res>t||(res==t&&vs<=(!vis[j])*c[j]))res=t,rt=j,vs=(!vis[j])*c[j];
		}
//		write(u,fu,v,fv,w),LF;s
		if(res<=w){
			val[fu][rt]=val[fv][rt]=0;
			vis[rt]=1;
			ans+=res;
		}else ans+=w;
		merge(u,v);
		if(++tot==n-1) break;	
	}
	write(ans),LF;
	return 0;
}
