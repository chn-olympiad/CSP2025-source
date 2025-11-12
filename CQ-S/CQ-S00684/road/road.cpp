#include<bits/stdc++.h>
using namespace std;
int tu[10005][10005];
int money[15][10005];
int tong[10005];
bool town[15];
int n,m,k;
int ans=0;
void dfs(int last){
	for(int i=1;i<=n;i++){
		int minn=100000000;
		if(i==last) continue;
		if(!tong[i]){
			if(tu[i][last]!=0){
				int minn=tu[i][last];
			}
			for(int j=1;j<=k;j++){
				if(town[j]){
					minn=min(money[j][i]+money[j][last],minn);
				}
				else{
					int p=minn;
					minn=min(money[j][i]+money[j][last]+money[j][0],minn);
					if(p!=minn||money[j][i]+money[j][last]+money[j][0]==p) town[j]=true;
				}
			}
		}
		ans+=minn;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		tu[x][y]=tu[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>money[i][0];
		for(int j=1;j<=n;j++){
			cin>>money[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
