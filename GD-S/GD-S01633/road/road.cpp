#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;

int f[N];
int fa(int u){
	if(f[u]==u) return u;
	else{
		f[u]=fa(f[u]);
		return f[u];
	}
}
void merge(int u,int v){
	int fu=fa(u),fv=fa(v);
	f[fu]=fv;
}

struct edge{
	int from,to,cost;
	friend bool operator < (edge u,edge v){
		return u.cost>v.cost;
	}
};

vector<edge> e;
priority_queue<edge> q;

int n,m,k,c[15],d[15][N],ans=2147483647;

int Kruskal(int u){
	
	if(c[u]>ans) return 2147483647;
	
	int tmp=0;
	
	for(int i=1;i<=n+1;i++) f[i]=i;
	while(!q.empty()) q.pop();
	
	int cnt=0;
	
	for(int j=0;j<m;j++) q.push(e[j]);
	if(u){
		cnt--;
		for(int j=1;j<=n;j++){
			q.push({j,n+1,d[u][j]});
		}
	}
	
	while(cnt<n-1){
		if(q.empty()){
			break;
		}
		edge t=q.top();
		if(fa(t.from)==fa(t.to)){
			q.pop();
			continue;
		}
		merge(t.from,t.to);
		tmp+=t.cost;
		q.pop();
		cnt++;
	}
	
	return tmp+c[u];
	
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>d[i][j];
	}
	
	ans=min(ans,Kruskal(0));

	for(int i=1;i<=k;i++){
		ans=min(ans,Kruskal(i));
		if((double)clock()/CLOCKS_PER_SEC > 0.9) break;
	}
	
	cout<<ans;
	
	return 0;
	
} 

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

//CCFÉñ»úÖúÎÒ£¡ 
