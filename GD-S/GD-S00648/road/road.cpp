#include<bits/stdc++.h>
using namespace std;

const int N=1e4+15;
int n,m,k,v=0;
int dis[N][N],vis[N],a[12]; 

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;


void go(int x){
	for(int i=1;i<=n+k;i++){
		if(dis[x][i]==0 || vis[i]==1) continue;
		q.push({dis[x][i],i}); 
	}
}
bool check(){
	for(int i=1;i<=(n+k)/2;i++){
		if(vis[i]==0) return false;
		if(vis[n+k-i]==0) return false;
	}
	return true;
}


int main(){
	freopen("road1.in","r",stdin);
	freopen("road1.out","w",stdout);
	cin>>n>>m>>k;
	int s,t,w;
	for(int i=1;i<=m;i++){
		cin>>s>>t>>w;
		dis[s][t]=w;
		dis[t][s]=w;
	}
	for(int j=1;j<=k;j++){
		cin>>a[j];
		for(int i=1;i<=n;i++){
			cin>>s;
			dis[i][j+n]=s;dis[j+n][i]=s;
		}
	}
	go(1);
	vis[1]=1;
	while (!q.empty()){
		pair<int,int>p=q.top();q.pop();
		if(vis[p.second]==1) continue;
		t=p.second;
		if(t>n){
			if(a[t-n]<2*q.top().first) {v+=a[t-n];a[t-n]=0;}
			else continue;
		}
		v+=p.first;
		vis[t]=1;
		if(check())break;
		go(t);
		
	}
	cout<<v;
	return 0;
}
