#include<bits/stdc++.h>
using namespace std;
#define int long long
int isA=1;
int n,m,k,cntedge,c[11];
long long ans=1e18;
struct Edge{
	int from,to,val;
}edge[2000006];
inline int read(){
	char ch=getchar();int v=0;
	for(;ch>'9'||ch<'0';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()){
		v=v*10+ch-'0';
	}
	return v;
}
void add(int u,int v,int w){
	++cntedge;
	edge[cntedge].from=u;
	edge[cntedge].to=v;
	edge[cntedge].val=w;
}
inline bool cmp(Edge a,Edge b){
	return a.val<b.val;
}
int fa[20004];
int getfa(int x){
	if(fa[x]!=x){
		fa[x]=getfa(fa[x]);
	}
	return fa[x];
}
void merge(int x,int y){
	int xf=getfa(x),yf=getfa(y);
	if(xf!=yf){
		fa[yf]=xf;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w);
	}
	for(int i=1;i<=k;++i){
		c[i]=read();add(n+i,n+k+i,c[i]);
		if(c[i]){isA=0;}
		for(int j=1;j<=n;++j){
			int x=read();add(n+i,j,x);
		}
	}
	sort(edge+1,edge+1+cntedge,cmp);
	for(int l=0;l<(1<<k);++l){
		if(isA){l=(1<<k)-1;}
		long long cnts=0;
		for(int i=1;i<=n;++i){
			fa[i]=i;
		}
		for(int j=1;j<=k;++j){
			if(1<<(j-1)&l){
				cnts+=1ll*c[j];fa[j+n]=j+n;fa[j+n+k]=j+n+k;
				merge(j+n,j+n+k);
			}else{
				fa[j+n]=fa[j+n+k]=0;
			}
		}
		for(int i=1;i<=cntedge;++i){
			int u=edge[i].from,v=edge[i].to;
			if(fa[u]==0||fa[v]==0){
				continue;
			}
			if(getfa(u)!=getfa(v)){
				merge(u,v);cnts+=1ll*edge[i].val;
			}
		}
		for(int i=1;i<=n;++i){
			if(getfa(i)!=getfa(1)){
				cnts=1e18;
			}
		}
		ans=min(ans,cnts);
	}
	cout<<ans<<endl;
	return 0;
}
