#include <bits/stdc++.h>

using namespace std;

int n,m,g[1010101],a;
bool vis[110][110];
int ans[110][110];
int dx[] = {0,1,-1,0};
int dy[] = {0,0,0,1};

struct link{
	int g , pm;
}po[100010];

bool kp(int a , int b){
	return a > b;
}

bool cmp(link a , link b){
	return a.g > b.g;
}

void dfs(int x,int y){
	for(int i = 1 ; i <= 3;i ++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if (vis[xx][yy] == false and xx <= n and yy <= m and xx >= 1 and yy >= 1){
			vis[xx][yy]=true;
			ans[xx][yy] = ans[x][y]+1;
			
			dfs(xx ,yy);
		}
	} 
}

signed main(){
	freopen("seat.in", "r" , stdin);
	freopen("seat.out" , "w" ,stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1 ; i <= n*m ; i++){
		cin >> g[i];
		
		po[i].g = g[i];
	}
	
	a=g[1];
	
	sort(g + 1 , g + 1 + n*m , kp);
	
	
	ans [1][1] = 1;
	vis[1][1]=true;
	
	dfs(1,1);
	
	for(int i=1 ; i <= n; i++){
		for( int j = 1; j<= m; j++){
			if(g[ans[i][j]] == a){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	
	return 0;
}
