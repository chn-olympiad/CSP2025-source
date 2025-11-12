#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,cnt=0,ans;
struct node{
	int u,v,w;
}g[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int c[N],mp[15][N];
bool fg[N];
bool tp=true;
int main(){
	freopen("road,in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	memset(fg,false,sizeof(fg));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[i].u =u,g[i].v =v,g[i].w =w;
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) tp=false;
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			if(mp[i][j]!=0) tp=false; 
		}
	}
	if(tp){
		cout<<0<<endl;
		return 0;
	}
	sort(g+1,g+1+n,cmp);
	for(int i=1;i<=m;i++){
		if(cnt==n) break;
		int u=g[i].u ,v=g[i].v,w=g[i].w;
		if(fg[u]&&fg[v]) continue;
		if(!fg[u]) cnt++;
		if(!fg[v]) cnt++;
		fg[u]=fg[v]=true;
		ans+=w;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
