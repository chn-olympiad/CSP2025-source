#include<iostream>
#include<queue>
#include<vector>
const int N=1e5+1e4+5,MX=1e9+2;
using namespace std;
int n,m,k,uu,vv,ww;
struct edge{
	int u,v;
};
int e[20003][20003];
struct cmp{
	bool operator()(edge a,edge b){
		return e[a.u][a.v]>e[b.u][b.v];
	}
};
priority_queue<edge,vector<edge>,cmp> q;
long long cnt;
int p[20003];
int find(int x){
	while(p[x]!=x){
		x=p[x];
	}return x;
}
void join(int x,int y){
	
	int xx=find(x);
	int yy=find(y);
	if(xx!=yy){
		p[xx]=yy;
	}
}
bool vis[10005];
void kr(){
	while(!q.empty()){
		edge h=q.top();
		q.pop();
		while(find(h.v)==find(h.u)&&!q.empty()){
			h=q.top();
			q.pop();
		}
		if(q.empty()){
			break;
		}
		int _u=h.u;
		int _v=h.v;
		cnt+=e[_u][_v];
		join(_u,_v);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=20000;i++){
		p[i]=i;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<=2*n;j++){
			e[i][j]==MX;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>uu>>vv>>ww;
		e[uu][vv]=ww;
		e[vv][uu]=ww;
		q.push((edge){uu,vv});
	}
	kr();
	cout<<cnt;
}
