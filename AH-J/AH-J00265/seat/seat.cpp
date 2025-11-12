#include <bits/stdc++.h>
using namespace std;
int a[15][15],n,m,g[105],gr,i;
bool cmp(int p,int q){
	return p>q;
}
void dfs(int x,int y,int k){
	if (k==i){
		cout << x << " " << y;
		return;
	}
	a[x][y]=1;
	if(y+1<=m and !a[x][y+1]){dfs(x,y+1,k+1);return;}
	if(y-1>=1 and !a[x][y-1]){dfs(x,y-1,k+1);return;}
	if(x+1<=n and !a[x+1][y]){dfs(x+1,y,k+1);return;}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (i=1;i<=n*m;i++)  cin >> g[i];
	gr=g[1],i=1;
	sort(g+1,g+n*m+1,cmp);
	while(true){
		if (gr==g[i])  break;
		i++;
	}
	dfs(1,1,1);
	return 0;
}
