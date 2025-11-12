#include <bits/stdc++.h>
using namespace std;

int n,m,k,be;bool f[1000005];int u[1000005],v[1000005],w[1000005];int b[11][10005];int dp[11];
void c(int i){
	dp[i] = 10000000;int x = 0;
		for(int j = i;j <= k;j++){
			for(int r = 1;r <= n;r++){
				dp[i] = min(dp[i],b[j][r]+b[j][i]+b[j][1]);
		}}
		for(int j = i;j <= k;j++){
			for(int r = 1;r <= n;r++){
				if(dp[i] == b[j][r]+b[j][1]) be = r;
		}
}}
int d(int i){int x=0,minn;f[i] = 1;
	for(int j = i+1;j <= m;j++){x = 0;
			if(v[i] == u[j]&&f[j] == 0){c(i);
				x += min(w[j],dp[i]);
				if(w[j] < dp[i]) {f[j] = 1;d(j);
				}
				else{
				f[be] = 1;d(be);
				}
				memset(f,1000005,0);
			}
			minn = min(minn,x);
	}
	return minn;
}
int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> u[i] >> v[i] >> w[i];	
	}
	for(int i = 1;i <= k;i++){
		for(int j = 0;j <= n;j++) cin >> b[i][j];
	}int minn;
		for(int i = 1;i<= m;i++)   minn = min(minn,d(i));
		cout << minn;
		return 0;
	}
	