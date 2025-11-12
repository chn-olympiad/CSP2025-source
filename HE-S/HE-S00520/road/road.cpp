#include<bits/stdc++.h>
using namespace std;

int const N = 1e3+10;
bool st[100][100];
int n,m,k,mp[N][N],x[N],a[N],cnt = 0,ans = 10000000000;
void dfs(int x,int y){
	if(st[x][y]){
		return;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			st[i][j] = true;
			cnt += mp[i][j];
			dfs(i,j);
			cnt-=mp[i][j];
			st[i][j] = false;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		cin>>mp[x][y];
	}
	for(int i = 1;i<=k;i++){
		cin>>x[i];
		for(int j = 1;j<=n;j++){
			cin>>a[j];
		}
	}
	for(int i = 1;i<=k;i++){
		for(int j = 1;j<=n;j++){
			for(int g = 1;g<=n;g++){
				mp[j][g] = a[j]+a[g]+x[i]; 
			}
		}
	}
	dfs(1,2);
	cout<<cnt;
	return 0;
}
