#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1e7+5;
int n,m,k,cnt;
struct Edge{
	int u,v,w,id;
}edge[maxn];
int a[maxn],fa[maxn];
int vis[maxn],w1[maxn];
int v[10005][10005];
bool cmp(Edge x,Edge y){
	return x.w+w1[x.id]<y.w+w1[y.id];
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void uniset(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
	}
}
void kruskal(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int ans=0;
	sort(edge+1,edge+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(find(edge[i].u)!=find(edge[i].v)){
			if(edge[i].id!=0&&vis[edge[i].id]==0){
				ans+=w1[edge[i].id];
				vis[edge[i].id]=1;
			}
			uniset(edge[i].u,edge[i].v);
			ans+=edge[i].w;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	memset(v,0x3f3f3f3f,sizeof(v));
	for(int i=1;i<=m;i++){
		int u,vv,w;
		cin>>u>>vv>>w;
		cnt++;
		edge[cnt].u=u;
		edge[cnt].v=vv;
		edge[cnt].w=w;
		v[u][vv]=v[vv][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>w1[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(j==k)continue;
				if(a[j]+a[k]>v[k][j]){
					continue;
				}
				cnt++;
				edge[cnt].u=k;
				edge[cnt].v=j;
				edge[cnt].w=a[k]+a[j];
				edge[cnt].id=i;
			} 
		}
	}
	kruskal();
	return 0;
}
/*
40-60pts
©³©©©©©©©©©©©©©©©· ©³©©©©©©©©©©©©©©©·          ©³©©©©©·                  ©³©©©©©·  
©«   ©³©©©©©·   ©« ©«   ©³©©©©©·   ©«          ©«    ©«                  ©«    ©«
©«   ©«    ©«   ©« ©«   ©«    ©«   ©«          ©«    ©«                  ©«    ©«
©«   ©»©©©©©¿   ©« ©«   ©»©©©©©¿   ©«  ©³©©©©©©©¿    ©»©©©©©©©·  ©³©©©©©©©¿    ©»©©©©©©©·
©«    ©²\    \©©©¿ ©«    ©²©©©©©©©©©¿  ©«                    ©«  ©«                    ©«
©«    ©« \    \    ©«    ©«            ©»©©©©©©©·    ©³©©©©©©©¿  ©»©©©©©©©·    ©³©©©©©©©¿
©«    ©«  \    \   ©«    ©«                    ©«    ©«                  ©«    ©«
©«    ©«   \    \  ©«    ©«                    ©«    ©«                  ©«    ©« 
©»©©©©©¿   ©»©©©©©¿©»©©©©©¿                    ©»©©©©©¿                  ©»©©©©©¿
*/
