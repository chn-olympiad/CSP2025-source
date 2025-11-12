#include<bits/stdc++.h>

using namespace std;

const int N=1e4+10;

int n,m,k,p;
int fa[N];
int ans=0,cnt=0;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
struct edge{
	int u,v,w;
}road[N*200];
bool cmp(const edge& x,const edge& y){
	return x.w<y.w;
}
int c[91];
int a[11][N];
int tie_node[11];
int tie(int x,int y){
	fa[find(x)]=find(y);
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<=n;i++){
		fa[i]=i;
		tie_node[i]=i;
	}
	cin>>n>>m>>k;
	p=n;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		road[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0)tie_node[i+n]=j;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==0)continue;
			road[++p]={i+n,j,a[i][j]};
		}
	}
	
	sort(road+1,road+1+p,cmp);
	for(int i=1;i<=p;i++){
		cout<<road[i].u<<" "<<road[i].v<<" "<<road[i].w<<endl;
	}
	
	for(int i=1;i<=p;i++){
		const edge tmp=road[i];
		if(find(tie_node[tmp.u])==find(tmp.v))continue;
		tie(tie_node[tmp.u],tmp.v);
		ans+=tmp.w;
		cnt++;
		if(cnt==p-1)break;
	}
	cout<<ans;
	

	return 0;
}
