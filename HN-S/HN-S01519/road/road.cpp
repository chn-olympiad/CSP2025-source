#include<bits/stdc++.h>
using namespace std;
int read(){
	int x,c;
	while((c=getchar())<'0'||c>'9');
	x=c^48;
	while((c=getchar())>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48);
	return x;
}
struct Edge{
	int x,y,w;
	void set(int _x,int _y,int _w){x=_x;y=_y;w=_w;}
	bool operator<(const Edge &a){return w<a.w;}
};
const int maxn=20020;
int fa[maxn];
int Find(int x){
	if(fa[x]<0)return x;
	return fa[x]=Find(fa[x]);
}
void getree(int n,Edge *E,int &S){
	for(int i=1;i<=n;i++)
		fa[i]=-1;
	int res=0,fx,fy;
	for(int i=0;i<S;i++)
		if(Find(E[i].x)!=Find(E[i].y)){
			fx=Find(E[i].x);fy=Find(E[i].y);
			if(fa[fx]<fa[fy])
				{fa[fx]+=fa[fy];fa[fy]=fx;}
			else
				{fa[fy]+=fa[fx];fa[fx]=fy;}
			E[res++]=E[i];
			if(fa[Find(1)]==-n)
				break;
		}
	S=res;
}
int n,m,k;long long ans;
int c[12];
Edge a[12][maxn],*lmp[12];int siz[12];
void search(int dep,int an,long long av){
	if(dep>k){
		for(int i=0;i<siz[dep-1];i++)
			av+=lmp[dep-1][i].w;
		if(av<ans)ans=av;
		return;
	}
	siz[dep]=siz[dep-1];
	for(int i=0;i<siz[dep];i++)
		lmp[dep][i]=lmp[dep-1][i];
	search(dep+1,an,av);
	an++;av+=c[dep];
	int x=siz[dep]-1,y=n;
	siz[dep]+=n;
	for(int i=siz[dep]-1;y>0;i--)
		if(x>=0&&lmp[dep][x].w>a[dep][y].w)
			lmp[dep][i]=lmp[dep][x--];
		else{
			lmp[dep][i].set(n+an,a[dep][y].y,a[dep][y].w);
			y--;
		}
	getree(n+an,lmp[dep],siz[dep]);
	search(dep+1,an,av);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	lmp[0]=new Edge[1000020];
	for(int i=1;i<12;i++)
		lmp[i]=new Edge[100020];
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=read();v=read();w=read();
		lmp[0][siz[0]++].set(u,v,w);
	}
	sort(lmp[0],lmp[0]+siz[0]);
	getree(n,lmp[0],siz[0]);
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j].set(-1,j,read());
		sort(a[i]+1,a[i]+n+1);
	}
	ans=0x7fffffffffffffffll;
	search(1,0,0);
	printf("%lld\n",ans);
	return 0;
}