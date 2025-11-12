#include <bits/stdc++.h>
using namespace std;
int n,m;
int b[200];
int a[15][15];
bool cmp(int a,int b){
	return a > b;
}
bool flag = 0;
void dfs(int x,int y,int u,int e,int w){
	if(u > n * m){flag = 1; return ;}
	a[x][y] = b[u];
	if((x == m && w == 1) || (x == 1 && w == 0)){
		if(!e){
			dfs(x,y + 1,u + 1,e + 1,w);
			if(flag) return ;
		}
		else if(e){
			e = 0;
			w = 1 - w;
		}
	}
	if(w == 1){
		dfs(x + 1,y,u + 1,e,w);
		if(flag) return ;
	}
	else if(w == 0){
		dfs(x - 1,y,u + 1,e,w);
		if(flag) return ;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i){
		cin >> b[i];
	}
	int g = b[1];
	sort(b + 1,b + n * m + 1,cmp);
	dfs(1,1,1,0,1);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(a[i][j] == g){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
