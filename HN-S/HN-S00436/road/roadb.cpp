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
struct P{
	int v,p;
	bool operator<(const P& y)const{
		if(v!=y.v) return v>y.v;
		return p>y.p;
	}
};
priority_queue<P> q[15]; 
void merge(int u,int v){
	int fu=find(u),fv=find(v);
	if(fu==fv) return;
	for(int i=1;i<=k;++i){
		if(val[fv][i]>val[fu][i]||val[fv][i]==0){
			val[fv][i]=min(val[fv][i],val[fu][i]);	
			q[i].push(P{val[fv][i],fv});
		}
	}
	fa[fu]=fv;
}
signed main(){
	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
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
			q[i].push((P){a[i][j],j});
		}
	}
	sort(e+1,e+m+1,[](node x,node y){return x.w<y.w;});
	int tot=0,ans=0;
	
	for(i=1;i<=m&&tot<n-1;){
		P p1={0,0},p2={0,0};
		int rt=0,res=oo;
		for(j=1;j<=k;++j){
			if(q[j].empty()) continue;
			P P1=q[j].top();q[j].pop();
			P P2={0,0};
			while(!q[j].empty()){
				P2=q[j].top();q[j].pop();
				write(P2.p),LF; 
				if(find(P2.p)==find(P1.p)) continue;
				break;
			}
//			write(P2.p,P1.p,find(P2.p),find(P1.p)),LF;
			if(find(P2.p)==find(P1.p)) continue;
			int t=(!vis[j])*c[j]+P1.v+P2.v;
			if(res>t){
				p1=P1,p2=P2;
				rt=j;
				res=t;
			}
		}
		int u1=find(p1.p),v1=find(p2.p),w1=res;
			write(u1,v1,w1),LF;
		
		u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv&&w<w1){
			merge(u,v);
			ans+=w;
			++i;
		}else if(w1<=w){
			val[u1][rt]=val[v1][rt]=0;
			vis[rt]=1;
			ans+=w1;
			merge(u1,v1);
		}
		if(++tot==n-1) break;	
	}
	write(ans),LF;
	return 0;
}
