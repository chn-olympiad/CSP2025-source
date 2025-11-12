#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long minn=0x3fffffffffffffff;
int f[1010][1010]={};	//修复i->j / j->i需要的最少资金 
bool vis[1010]={};
void test(){
	cout<<"-------------------------"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"-------------------------"<<endl;
}
void dfs(int x,int y,long long cnt,int ff){	//x行 y列 
	if(minn<cnt || y>n)
		return;
	if(ff==n){
		minn=min(minn,cnt);
	}
//	cout<<x<<" "<<y<<" "<<cnt+f[x][y]<<endl;
	if(!vis[y] && x!=y){
		vis[x]=true;
		dfs(y,1,cnt+f[x][y],ff+1);//选
		vis[x]=false;
	}
	dfs(x,y+1,cnt,ff); 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,v;
		cin>>a>>b>>v;
		f[a][b]=f[b][a]=v;
	}
	for(int i=1;i<=k;i++){
		int v[n+1]={};
		scanf("%d",&v[0]);
		for(int j=1;j<=n;j++)
			scanf("%d",&v[j]);
		for(int a=1;a<n;a++){
			for(int b=a+1;b<=n;b++){
				f[a][b]=min(f[a][b]==0?0x3f:f[a][b],v[a]+v[b]+v[0]);
				f[b][a]=min(f[b][a]==0?0x3f:f[b][a],v[a]+v[b]+v[0]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][k]=min(f[i][k],f[i][j]+f[j][k]);
			}
		}
	}
	//已知从i->j / j->i 所需要的最小资金 求最短连通路 
	dfs(1,2,0,1);
//	test();
	cout<<minn<<endl;
	return 0;
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
