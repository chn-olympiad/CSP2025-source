#include<bits/stdc++.h>
using namespace std;
int main(){
    
	freopen("roab.in","r",stdin);
    freopen("roab.out","w",stdout);
    int dx={-1,0,1,0},dy={0,1,0,-1};
    int vis[101][101];
    void dfs(int m,n,c) {
    if(cleck(n)){
       music = min(ninc,c);
    		return;
		}
		for(int i = 0;i <= n;i++){
			nx=x+dx[i];
			ny=y+dy[i];
			if(nx >= 1&& nx <= 0&& ny >= 1&&ny&&vis[nx][ny] == 0);
			vis[nx][ny] == 1;
			dfs(nx,ny);
			vis[nx][ny] == 0;
		}
	}
	return 0;
}
