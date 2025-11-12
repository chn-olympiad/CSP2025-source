#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[15][10005],c[10005],tot,fa[10005],ans,ff[10005][15],s[10005][15],ans2,mm[15];
bool vis[10005];
int get(int u){
	if(u==fa[u])return u;
	return fa[u]=get(fa[u]);
}
struct node{
	int u,v,w;
}ed[1000005];
vector<node>tr;
vector<pair<int,int>>G[10005];
bool cmp(node a,node b){
	return a.w<b.w;
}
void dfs(int u,int fa,int f){
	ff[u][f]=fa;vis[u]=1;
	for(pair<int,int>v:G[u]){
		if(v.first==fa||vis[v.first])continue;
		dfs(v.first,u,f);
		s[v.first][f]=v.second;
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		ed[tot++]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j]; 
	}	
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(ed,ed+tot,cmp); 
	for(int i=0;i<tot;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		if(get(u)==get(v))continue;
		fa[get(u)]=get(v);tr.push_back(ed[i]);ans+=w;
	}
//	cout<<ans<<'\n';
	ans2=ans;
	int sz=tr.size();
	for(int i=0;i<sz;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		G[u].push_back({v,w});G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int minn=1e9,mini;
		for(int j=1;j<=n;j++){
			if(minn>a[i][j])minn=a[i][j],mini=j;
		}
		mm[i]=mini;
		dfs(mm[i],0,i);
		memset(vis,0,sizeof(vis));
	}
	
//	for(int i=1;i<=k;i++){
//		cout<<i<<' ';
//		for(int j=1;j<=n;j++)cout<<ff[j][i]<<' '<<s[j][i]<<' ';
//		cout<<'\n';
//	}
	for(int t=1;t<(1<<k);t++){
		vector<int>xz;
		for(int i=1,x=t;i<=10&&x>0;i++,x>>=1){
			if(x%2)xz.push_back(i);
		}
		int sum=ans,sz=xz.size();
		for(int i:xz)sum+=(c[i]+a[i][mm[i]]);
		bool ck[15]={0};
		for(int zz=1;zz<=n;zz++)
			for(int i=0;i<sz;i++){
				if(ck[xz[i]])continue;
				int minn=1e18;
				for(int j=i;j<sz;j++)
					if(ff[zz][xz[j]]==ff[zz][xz[i]])ck[xz[j]]=1,minn=min(minn,a[xz[j]][zz]);
				sum=sum+(minn<s[zz][xz[i]]?minn-s[zz][xz[i]]:0);
			}
		ans2=min(ans2,sum);
	}
	cout<<ans2<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


