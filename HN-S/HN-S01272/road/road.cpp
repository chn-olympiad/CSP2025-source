#include<bits/stdc++.h>
#define int long long
using namespace std;
struct paa{
	int u1,v1,w1;
}e[1100010];
int fa[10100];
int f1[10010];
int vis[10010];
int a[10010];
int cnt;
int n,m,k,s,minn=1e15;
bool cmp(paa x,paa y){
	return x.w1<y.w1;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs(int x,int sum){
	if(sum>minn)return;
	if(x==s+1){
		for(int i=1;i<=s;i++)fa[i]=i;//cout<<vis[i]<<" ";cout<<"\n";
		for(int i=1;i<=n;i++)f1[i]=1; 
		int ans=0;
		for(int i=1;i<=cnt;i++){
			int w=e[i].w1;
			int u=e[i].u1;
			int v=e[i].v1;
			int fu=find(u);
			int fv=find(v);
			if(vis[u]==0||vis[v]==0||fu==fv){
				continue;
			}
			fa[fu]=fv;
		//	cout<<f1[fv]<<" "<<f1[fu]<<" ";
			f1[fv]+=f1[fu];
//			cout<<f1[fv]<<"\n";
//			for(int i=1;i<=s;i++)
//				cout<<fa[i]<<" ";
//			cout<<"\n";
//			for(int i=1;i<=n;i++)
//			cout<<f1[i]<<" ";
//			cout<<"\n";
			ans+=w;
		//	cout<<ans<<"\n";
			if(f1[fv]==n)break;
		} 
	//	for(int i=1;i<=s;i++)
	//		cout<<fa[i]<<" ";
	//	cout<<"\n";
		int f=0;
	//	for(int i=1;i<=n;i++)
	//	cout<<f1[i]<<" ";
	//	cout<<"\n";
		for(int i=1;i<=n;i++)
			if(f1[i]==n)f=1;
		if(f)
		minn=min(minn,ans+sum);
		//cout<<ans<<" "<<minn<<"\n";
		return;
	}
	dfs(x+1,sum);
	vis[x]=1;
	dfs(x+1,sum+a[x]);
	vis[x]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>m>>k;
	s=n+k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>a[n+i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e[++cnt]={n+i,j,w};
		} 
	}
	for(int i=1;i<=n;i++)vis[i]=1;
	sort(e+1,e+1+cnt,cmp);
//	for(int i=1;i<=cnt;i++){
//		cout<<e[i].u1<<" "<<e[i].v1<<" "<<e[i].w1<<"\n";
//	}
	dfs(n+1,0);
	cout<<minn;
	return 0;
}

