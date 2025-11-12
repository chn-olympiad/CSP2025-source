#include <bits/stdc++.h>
using namespace std;
int n,m,k,len;
long long ans;

struct ly{ 
	int u,v,val;
} edge[1000010];
void add(int u,int v,int w){
	edge[++len].u=u;
	edge[len].v=v;
	edge[len].val=w;
}
bool cmp(ly x,ly y){
	return x.val<y.val;
}

int fa[100010];
int find(int x){
	if(fa[x]==-1){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void ins(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}

int a[15][10010],c[15],cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	memset(fa,-1,sizeof(fa));
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(edge+1,edge+len+1,cmp);
	for(int i=1;i<=len;i++){
		if(find(edge[i].v)==find(edge[i].u)){
			continue;
		}
		ins(edge[i].v,edge[i].u);
		ans+=edge[i].val;
	}
	cout<<ans;
	return 0;
}
