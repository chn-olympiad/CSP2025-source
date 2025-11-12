#include <bits/stdc++.h>
using namespace std;

long long n, m, k, minn[10005], x, y, z, flag[15], vis[10005], b[15][10005], dis[15][10005], ans;
char c;

struct note{
	long long u, w;
};

void read(long long &x){
    x = 0, c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') x = (x << 3) + (x << 1), x += c ^ 48, c = getchar();
}

vector <note> v[10005];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	read(n), read(m), read(k);
	for(int i = 1; i <= m; i++) read(x), read(y), read(z), v[x].push_back({y, z}), v[y].push_back({x, z});
	for(int i = 1; i <= k; i++)
	    for(int j = 0; j <= n; j++)
	        read(b[i][j]);
	for(int i = 0; i <= k; i++) 
	    for(int j = 0; j <= n; j++)
	        dis[i][j] = 1e18;
	dis[0][1] = 0;
	for(int _ = 1; _ <= n; _++){
		x = 0;
		for(int i = 1; i <= n; i++)
		    if(vis[i] == 0){
		        for(int j = 0; j <= k; j++)
		            if(dis[j][i] < dis[minn[i]][i]) minn[i] = j;
		        if(dis[minn[i]][i] < dis[minn[x]][x]) x = i;
		    }
		vis[x] = 1, flag[minn[x]] = 1, ans += dis[minn[x]][x];
		for(int i = 0; i < v[x].size(); i++)
		    if(vis[v[x][i].u] == 0) dis[0][v[x][i].u] = min(dis[0][v[x][i].u], v[x][i].w);
		for(int i = 1; i <= k; i++)
	    	for(int j = 1; j <= n; j++)
	    	    if(vis[j] == 0)
	    	        if(flag[i] == 0)
	    	    		dis[i][j] = min(dis[i][j], b[i][0] + b[i][x] + b[i][j]);
	    	    	else dis[i][j] = min(dis[i][j], b[i][j]);
	}
	cout << ans << "\n";
	return 0;
} 
