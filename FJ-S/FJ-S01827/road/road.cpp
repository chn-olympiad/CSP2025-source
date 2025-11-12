#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=2e9,a[15][20005],c[15],used[15],f[20005],siz[20005];
struct node{
	int u,v,w;
}e[7000000];
bool cmp(const node&x,const node&y){
	return x.w<y.w;
}
int Find(int v){
	return f[v]==v?v:f[v]=Find(f[v]);
}
void merge(int u,int v){
	if(siz[u]>siz[v])f[v]=u,siz[u]+=siz[v];
	else f[u]=v,siz[v]+=siz[u];
}
int min_tree(){
	int tot=n,cnt=m;
	for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
	for(int i=1;i<=k;i++){
		if(used[i]){
			for(int j=1;j<=n;j++){
				for(int l=j+1;l<=n;l++){
					e[++cnt]={l,j,a[i][j]+a[i][l]};
				//	e[++cnt]={j,n+i,a[i][j]};
				}
			}
		}
	}
	sort(e+1,e+1+cnt,cmp);
	int res=0;
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int t1=Find(u),t2=Find(v);
		if(t1==t2)continue;
	//	cout<<t1<<' '<<t2<<' '<<w<<endl;
		merge(t1,t2);
		res+=w;
		tot--;
		if(tot==1)break;
	}
	return res;
}
int min_tree2(){
	int tot=n;
	for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
	sort(e+1,e+1+m,cmp);
	int res=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int t1=Find(u),t2=Find(v);
		if(t1==t2)continue;
	//	cout<<t1<<' '<<t2<<' '<<w<<endl;
		merge(t1,t2);
		res+=w;
		tot--;
		if(tot==1)break;
	}
	return res;
}
void dfs(int s,int cost){
	if(s==k+1){
		int res=min_tree();
		ans=min(ans,res+cost);
		cout<<ans<<endl;
		return;
	}
	used[s]=0;
	dfs(s+1,cost);
	used[s]=1;
	dfs(s+1,cost+c[s]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
	//	mp[u][v]=mp[v][u]=min(w,mp[u][v]);
		e[i]={u,v,w};
	//	e[i]={v,u,w};
	}
	if(k==0){
		cout<<min_tree2()<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
