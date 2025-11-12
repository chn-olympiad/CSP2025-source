#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,m,k;
struct edge{
	int x,y,s;
}a[N];
int b[20],ma[20][N];
bool cmp(edge a,edge b){
	return a.s<b.s;
}
struct node{
	int to,s;
};
vector<node>e[N];
int d[N];
int ans=INT_MAX;
//void dfs(int num,int sum,int last){
//	if(vis[num])return;
//	vis[num]=sum;
//	ji++;
//	if(ji==n){
//		cout<<sum;
//		return;
//	}
//	for(auto v:e[num]){
//		if(v.to!=last)dfs(v.to,sum+v.s,num);
//	}
//	vis[num]=0;
//}
int ji=0;
void bfs(){
	queue<node>q;
	q.push({1,0});
	while(!q.empty()){
		int u=q.front().to;
		int s=q.front().s;
		q.pop();
		if(d[u]==0){
			ji++;
		}
		if(ji==n){
			ans=min(ans,s);
			break;
		}
		d[u]=s;
		if(d[u]<s)continue;
		if(ji==n){
			ans=min(ans,s);
			continue; 
		}
		for(auto v:e[u]){
			q.push({v.to,s+v.s});
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].s;
		e[a[i].x].push_back({a[i].y,a[i].s});
		e[a[i].y].push_back({a[i].x,a[i].s});
	}
	int check=0;
	for(int i=1;i<=k;i++){
		cin>>b[i];
		if(b[i])check=1;
		for(int j=1;j<=n;j++){
			cin>>ma[i][j];
			if(ma[i][j])check=1;
		}
	}
	if(!check){
		cout<<0;
		return 0;
	}
	bfs();
	cout<<ans;
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
