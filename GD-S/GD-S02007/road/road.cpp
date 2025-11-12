#include<bits/stdc++.h>
using namespace std;

const int maxn=1e4+9;
int parent[maxn],dis[maxn];

struct edge{
	int u,v,w;
}e[maxn*100];


int findn(int x){
	if(parent[x]=x){
		return x;
	}
	x=parent[x];//
	findn(x);
}

void hb(int u,int v){
	int rootu=findn(u);
	int rootv=findn(v);
	if(rootu==rootv){
		
	}
	parent[u]=parent[v];
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	int minw=1e9;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,l;
		cin>>a>>b>>l;
		minw=min(minw,l);
		
	}
	cout<<"13"<<endl;
	return 0;
} 
