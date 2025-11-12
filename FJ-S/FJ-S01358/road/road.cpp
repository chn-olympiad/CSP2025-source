#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
int n,m,k;
int u,v,w;
int ans=0;
int x,y;
int maxn=0;
struct node{
	int u,v,w;
	bool fl=false;
}a[2*N];
vector <pair<int,int> > ve[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int b[15];
int c[15][N];
bitset<N> vis;
queue <int> q;
bool pd(){
	vis.reset();
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int dlt=q.front();
		q.pop();
		for(auto i:ve[dlt]){
			if(i.second<=maxn){
				if(vis[i.first]) continue;
				vis[i.first]=1;
				q.push(i.first);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) return false;
	}
	return true;
}
void bfs(){
	sort(a+1,a+1+m,cmp);
	int cnt=0;
	while(!pd()){
		cnt++;
		a[cnt].fl=true;
		maxn=a[cnt].w;
	}
	for(int i=1;i<=cnt;i++){
		ans+=(a[i].fl)*a[i].w;
	} 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[i].u=u,a[i].v=v,a[i].w=w;
		a[n+i].v=u,a[n+i].u=v,a[n+i].w=w;
		ve[u].push_back(make_pair(v,w));
		ve[v].push_back(make_pair(u,w)); 
	} 
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>c[j][i];
		}
	}
	if(k==0){
		bfs();
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
/*
2 2 0
1 2 3
2 1 4

*/
