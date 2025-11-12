#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> edges[10011];
int a[10011][10011];
bool b[10011];
int ans = 1e9;
inline void dfs(int x,int num){
	bool f = true;
	for (int i=1;i<=n;i++)
	    if(!b[i]){
	    	f = false;
	    	break;
		}
	if(f){
		ans = min(ans,num);
		return;
	}
	for(auto y:edges[x]){
		if(!b[y]){
			b[y] = true;
		    dfs(y,num+a[x][y]);
		    b[y] = false;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf ("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf ("%d%d%d",&x,&y,&z);
		edges[x].push_back(y);
		edges[y].push_back(x);
		a[x][y] = a[y][x] = z;
	}
	for (int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			edges[j].push_back(n+i);
			edges[n+i].push_back(j);
			a[n+i][j] = a[j][n+1] = x+c;
		}
	}
	dfs (1,0);
	printf ("%d",ans);
} 
