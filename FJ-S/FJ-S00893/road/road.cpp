#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11],vis[101][1000001];
int a[101][1000001];
long long ans;
/*vector<int> a[11];
vector<int> head;
vector<vector<int>> edge;
queue<int> q;
inline bool cmp(vector<vector<int>> x,vector<vector<int>> y){
	return x<y;
}*/
/*inline void dijstra(){
	while(!q.empty()){
		for(int i=1;i<=(int)head.size()+1;i++){
			if(head[i]==0)q.push(i);
		}
		int to=q.front(),mi=0x3f3f3f,vv;
		for(int i=1;i<=(int)head.size();i++){
			if(edge[to][i]<mi&&vis[i]!=1)
				mi=edge[to][i],vv=i;
		}
		vis[to]=1,vis[vv]=1;
		if(mi!=0x3f3f3f)ans+=mi;
		if(--head[vv]==0)q.push(vv);
	}
}*/
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;a[v][u]=w;
		/*edge[u].push_back(v);
		edge[u][v]=w;head[v]++;*/
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];int x;
		for(int j=1;j<=n;j++)
			cin>>x;
	}//dijstra();
	for(int i=1;i<=n;i++){
		sort(a[i]+1,a[i]+n+1);
		for(int j=i;j<=m;j++)
		if(vis[i][j]==0){
			vis[i][j]=1;vis[j][i]=1;
			ans+=a[i][j];
			break;
		}
	}
	cout<<ans;
	return 0;
}

