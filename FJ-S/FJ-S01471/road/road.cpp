#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

int n,m,k;
struct edge{
	fr,to,w;
};
edge e[1000005];
bool vis[10005]={0};
int fa[10005]={0};

bool cmp(edge a,edge b){
	return a.w>b.w;
}
bool find(int a,int b){
	if(fa[a]==fa[b]) return true;
	else return fa[a]=fa[b]=find()
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	long long ans=0;
	for(int i=0,u,v,w;i<m;i++){
		cin>>u>>v>>w;
		e[i].fr=u;
		e[i].to=v;
		e[i].w=w;
	}
	sort(e,e+m,cmp);
	while(true){
		
	}
	cout<<ans;
	return 0;
}
