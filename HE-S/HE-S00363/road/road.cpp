#include<bits/stdc++.h>

using namespace std;

const int N=1e4+10;

int n,m,k,c[N];
int a[12][N],fa[N],tot;

struct edge{
	int u,v,w;
	bool operator<(const edge&x) const 
      { return x.w < w; }
}t[N];

int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}

void Kruscal(){
	priority_queue<edge>q;
	for(int i=1;i<=m;i++){
		q.push(t[i]);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	while(!q.empty()){
		edge t=q.top();q.pop();
		int u=t.u,v=t.v,w=t.w;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			tot+=w;
			//cout<<tot<<endl;
		}
	}
	cout<<tot;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>t[i].u>>t[i].v>>t[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0){
		Kruscal();
		exit(0);
	}else{
		
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
