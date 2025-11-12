#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e6+10;
int n,m,k,a[10][maxn],c[maxn],fa[maxn],ans=LLONG_MAX,cnt,cnt2,sum1;
int vis[20];
struct node{
	int u,v,w;
}g[maxn<<2],g2[maxn<<2];
bool cmp(node xx,node yy){
	return xx.w<yy.w;
}
inline void init(){
	for(int i=1;i<=n+k+1;i++){
		fa[i]=i;
	}
}
inline int Find(int x){
	return x==fa[x]?fa[x]:fa[x]=Find(fa[x]);
}
inline void Merge(int x,int y){ 
	fa[x]=y; 
}
inline bool Judge(int x,int y){
	return Find(x)==Find(y);
}
void kru(){
	init(); 
	sort(g2+1,g2+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int u1=g2[i].u,v1=g2[i].v,w1=g2[i].w;
		if(Find(u1)!=Find(v1)){
			Merge(Find(u1),Find(v1)); 
			//cout<<u1<<' '<<Find(u1)<<' '<<v1<<' '<<Find(v1)<<endl;
			sum1+=w1;
		}
	}
}
void dfs(int i){
	if(i==k+1){
		int sum=0;
		sum1=0;
		for(int i=1;i<=k;i++){
			if(vis[i]){
				sum+=c[i];
			}
		}
		cnt=0;
		for(int i=1;i<=m;i++){
			g2[++cnt]={g[i].u,g[i].v,g[i].w};
			g2[++cnt]={g[i].v,g[i].u,g[i].w};
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(vis[j]){
					g2[++cnt]={i,n+j,a[j][i]};
					g2[++cnt]={n+j,i,a[j][i]};				
				}
			}
		}
		//sort(g2+1,g2+cnt+1,cmp);
		//for(int i=1;i<=cnt;i++){
		//	cout<<g2[i].u<<' '<<g2[i].v<<' '<<g2[i].w<<endl; 
		//}
		kru();
		//cout<<sum<<' '<<sum1<<' '<<cnt<<endl;
		ans=min(ans,sum+sum1);
		return;
	}
	vis[i]=1;
	dfs(i+1);
	vis[i]=0;
	dfs(i+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)flag=0;
		}
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			g2[++cnt]={g[i].u,g[i].v,g[i].w};
			g2[++cnt]={g[i].v,g[i].u,g[i].w};
		}
		kru(); 
		cout<<ans;
		return 0;
	}else if(flag){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
RP++
*/
