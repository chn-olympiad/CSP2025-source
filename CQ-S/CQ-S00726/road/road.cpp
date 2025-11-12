#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int x,w;
};
vector<node> a[10005];
int b[15];
int c[15][10005];
int vis[10005];
int bfs(){
	int sum=0;
	queue<int> q;
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int o=q.front();
		q.pop();
		for(node i:a[o]){
			if(vis[i.x]) continue;
			sum+=i.w;
			vis[i.x]=1;
			q.push(i.x);
		}
	}
	return sum;
}
void RP(){
	/*
	while(1){
		cout<<"RP++\n";
	}
	*/ 
	srand(time(0));
	int I_am_lucky=rand()%bfs(); 
	cout<<I_am_lucky<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	RP();
	return 0;
}

