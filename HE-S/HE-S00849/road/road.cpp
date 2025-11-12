#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int n,m,k;
int c,w[11000];
struct edge{int u,v,w;}e[6000000];
int fa[11000],cnt,ans,a[11000][11000];
bool cmp(edge a,edge b){return a.w<b.w;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
inline void kruskal(){
	cnt=0,ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(cnt==n-1) continue;
		if(find(e[i].u)==find(e[i].v)) continue;
		merge(e[i].u,e[i].v);
		cnt++;
		ans+=e[i].w;
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read();v=read();w=read();
		e[i].u=u,e[i].v=v,e[i].w=w;
		a[u][v]=i;
		a[v][u]=i;
	}
	for(int i=1;i<=k;i++){
		c=read();
		for(int v=1;v<=n;v++){
			w[v]=read();
			for(int u=1;u<v;u++){
				if(a[u][v]!=0){
					e[a[u][v]].w=min(e[a[u][v]].w,w[u]+w[v]+c);
				}else{
					m++;
					e[m].u=u,e[m].v=v,e[m].w=w[u]+w[v]+c;
				}
				
			}
		}
	}
	kruskal();
	return 0;
}
