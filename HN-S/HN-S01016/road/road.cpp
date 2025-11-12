#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
struct node{
	int u,v,w;
	int f;
	int l;
}a[N];
int sum[N],fa[N];
//const int N=1e4+5,M=1e6+5;
//int sum[N];
//int dis[N],vis[N];
//vector<pair<int,int> > a[M];
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
//void dijkstra(){
//	q.push({0,1});
//	dis[1]=0;
//	while(q.size()>0){
//		int id=q.top().first;
//		int sum=q.top().second;
//		q.pop();
//		if(vis[sum]){
//			continue;
//		}
//		vis[sum]=1;
//		for(int i=0;i<a[sum].size();i++){
//			if(dis[a[sum][i].first]>dis[sum]+a[sum][i].second){
//				dis[a[sum][i].first]=dis[sum]+a[sum][i].second;
//				q.push({dis[a[sum][i].first],a[sum][i].first});
//			}
//		}
//	}
//	return ;
//}
int cmp(node a,node b){
	return a.w<b.w;
}
int find(int u){
	if(fa[u]==u){
		return u;
	}
	return fa[u]=find(fa[u]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].f=0;
	}
	int z=0;
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>sum[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				z++;
				a[z+m].u=j;
				a[z+m].v=k;
				a[z+m].w=c+sum[j]+sum[k];
				a[z+m].f=1;
				a[z+m].l=c;
			}
		}
	}
	sort(a+1,a+1+z+m,cmp);
//	for(int i=1;i<=z+m;i++){
//		cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<" "<<a[i].f<<" "<<a[i].l<<endl;
//	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
//	for(int i=1;i<=k+m;i++){
//		cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
//	}
//	cout<<endl;
	int pp=0;
	int cnt=0;
	int f1=0;
	for(int i=1;i<=k+m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			fa[find(a[i].u)]=find(a[i].v);
			pp+=a[i].w;
		//	cout<<"a[i].w:"<<a[i].w<<endl;
			cnt++; 
			if(f1==1){
				pp-=a[i].l;
			}
			if(f1==0&&a[i].f==1){
				f1=1;
			}
		}
		if(cnt==n-1){
			break;
		}
	}
	cout<<pp;
//	int n,m,k;
//	cin>>n>>m>>k;
//	for(int i=1;i<=m;i++){
//		int u,v,w;
//		cin>>u>>v>>w;
//		a[u].push_back({v,w});
//		a[v].push_back({u,w});
//	}
//	for(int i=1;i<=k;i++){
//		int c;
//		cin>>c;
//		for(int j=1;j<=n;j++){
//			cin>>sum[j]; 
//		} 
//		for(int j=1;j<=n;j++){
//			for(int k=1;k<=n;k++){
//				a[j].push_back({k,c+sum[j]+sum[k]});
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		dis[i]=2e9;
//	}
//	memset(vis,0,sizeof(vis));
//	dijkstra();
//	int maxx=-1e9;
//	for(int i=1;i<=n;i++){
//		maxx=max(maxx,dis[i]);
//	}
//	cout<<maxx;
	return 0;
} 
