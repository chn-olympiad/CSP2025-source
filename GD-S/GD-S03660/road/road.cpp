#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 11010
#define MAXM 2100010
ll n,m,k,ans,top,cnt;
ll fa[MAXN],c[110],a[110][MAXN],dis[1010][1010];
bool flag[110],vis[110];
struct edge{
	ll u,v,w;
}e[MAXM],p[MAXM];
bool cmp(edge pre,edge nxt){
	return pre.w<nxt.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void kruskal1(){
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u==v) continue;
		fa[u]=v;
		cnt++;
		ans+=e[i].w;
		if(cnt==n-1) return;
	}
}
void kruskal2(){
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u==v) continue;
		fa[u]=v;
		cnt++;
		ans+=e[i].w;
		p[cnt].u=e[i].u;
		p[cnt].v=e[i].v;
		p[cnt].w=e[i].w;
		if(cnt==n-1) break;
	}
//	cout<<ans<<"\n";
	for(int i=1;i<=k;i++){
		for(int j=1;j<=cnt;j++){
			int k=(vis[i]==false?c[i]:0);
//			cout<<p[j].w<<" "<<k<<" "<<a[i][p[j].u]<<" "<<a[i][p[j].v]<<" "<<ans<<"\n";
			if(p[j].w>k+a[i][p[j].u]+a[i][p[j].v]){
				if(!vis[i]) vis[i]=true;
				ans=ans-p[j].w+k+a[i][p[j].u]+a[i][p[j].v];
			}
		}
	}
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	top=m;
//	bool flag=true;
	for(int i=1;i<=k;i++){
		cin>>c[i];
//		if(c[i]!=0) flag=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		} 
	}
	if(k==0){
		kruskal1();
		cout<<ans<<"\n";
	}
	else{
		kruskal2();
		cout<<ans<<"\n"; 
	}
	return 0;
}

