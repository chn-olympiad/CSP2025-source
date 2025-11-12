#include <iostream>
#include <cstdio>
using namespace std;
bool flag = 1;
int n,m,k,x,y,w[10005][10005],c[15],a[15][10005];
bool cw[10005][10005];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++){
		cin >> x >> y;
		cin >> w[x][y];
		ans += w[x][y];
		cw[x][y] = 1;
		if(w[x][y])flag = 0;
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		if(c[i])flag = 0;
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			if(a[i][j])flag = 0;
		}
	}
	if(flag)cout << 0;
	else cout << ans;
	return 0;
}
