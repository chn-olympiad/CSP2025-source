#include<bits\stdc++.h>
using namespace std;
int a[10001][10001],n,v,m,minn=1145141919,c[10001][10001];
bool vis[11451][11451];
void dfs(int step,int key,int whe,int last){
	if(step==n+1){
		minn=min(minn,key);
		return;
	}
	vis[whe][last]=1;
	vis[last][whe]=1;
	for(int i=1;i<=n;i++){
		if(i!=whe&&!vis[whe][i])dfs(step+1,key+a[whe][i],i,whe);
	}
	vis[whe][last]=0;
	vis[last][whe]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>v;
	for(int i=1;i<=m;i++){
		int k,u,key;
		cin>>k>>u>>key;
		a[k][u]=key;
		a[u][k]=key;
	}
	for(int i=1;i<=v;i++){
		int value,p[n+1];
		cin>>value;
		for(int j=1;j<=n;j++){
			cin>>p[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(c[j][k]!=0)c[j][k]=min(p[j]+p[k]+value,c[j][k]);
				else c[j][k]=p[j]+p[k]+value;
				c[k][j]=c[j][k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=0)a[i][j]=min(a[i][j],c[i][j]);
			else a[i][j]=c[i][j];
		}
	}
	for(int i=1;i<=n;i++)dfs(1,0,i,0);
	cout<<minn;
	return 0;
}
