#include <bits/stdc++.h>
using namespace std;
int n,m,k,v,u,qqq,ans;
int w[1005][1005];
int ww[12][1005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(w,0x3f3f,sizeof(w));
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> qqq;
		w[u][v]=qqq;
		w[v][u]=qqq;
	}
	for(int i = 1;i <= k;i++){
		cin >> ww[i][0];
		for(int j = 1;j <= n;j++){
			cin >> ww[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= m;k++){
				w[i][j]=min(w[i][j],ww[k][0]+w[k][i]+w[k][j]);
			}
		}
	}
	for(int i = 1;i < n;i++){
		ans += w[i][i+1];
	}
	cout << ans;
}