#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0x3f3f3f3f;
vector<int> road[10005];
int qz[5005][5005];
bool xf[15][10005];
int cost[15];
bool csh[15];
int xfc[15][10005];
bool yf[10005];
void dfs(int dep,int now,int c){
	//cout<<"dep:"<<dep<<" now:"<<now<<" c:"<<c<<endl;
	if(dep==n){
		ans=min(ans,c);
		return;
	}
	for(int i=0;i<road[now].size();i++){
		int to=road[now][i];
		if(!yf[to]){
			
			for(int j=1;j<=k;j++){
				int rc=0;
				if(!xf[j][now]){
					if(!csh[j]){
						rc+=cost[j];
					}
					rc+=xfc[j][now];
				}
				if(!xf[j][to]){
					rc+=xfc[j][to];
				}
				xf[j][now]=true;
				xf[j][to]=true;
				csh[j]=true;
				yf[to]=true;
				dfs(dep+1,to,c+rc);
				yf[to]=false;
				xf[j][now]=false;
				xf[j][to]=false;
				csh[j]=false;
			}
			yf[to]=true;
			dfs(dep+1,to,c+qz[now][to]);
			yf[to]=false;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		road[x].push_back(y);
		road[y].push_back(x);
		qz[x][y]=z;
		qz[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=0;j<n;j++){
			cin>>xfc[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		yf[i]=true;
		dfs(1,i,0);
		yf[i]=false;
	}
	cout<<ans;
	return 0;
}
