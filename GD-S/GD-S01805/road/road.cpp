#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
const int INF=0x3f3f3f3f3f;
int n,m,k; 
int head[N],w[N],ne[N],to[N],id;
void add(int x,int y,int z){
	to[++id]=y,ne[id]=head[x],w[id]=z,head[x]=id;
}
int vis[2*N];
struct node{
	int dis, u, v;
};
vector<node>v;
int dfs(){
	int ans=0,k=n-1;
	for(int i=0;i<v.size();i++){
		int u=v[i].u;
		int vv=v[i].v;
		if(vis[u]==vis[vv]&&vis[u]==1)continue;
		k--;
		ans+=v[i].dis;
		vis[u]=vis[vv]=1;
		if(k==0)break;
	}
	return ans;
}
bool cmp(node x,node y){
	return x.dis<y.dis;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		int u,vv,w;
		cin>>u>>vv>>w;
		add(u,vv,w);
		add(vv,u,w);
		v.push_back({w,u,vv});
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			add(n+i,j,w);
			add(j,n+i,c);
		}
	}
	m=n+k+1;
	if(k==0){
		cout<<dfs()<<endl;
	}
	else{
		cout<<dfs()<<endl;
	} 
	return 0;
}

