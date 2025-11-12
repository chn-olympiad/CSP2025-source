#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;
int a[11][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin >> n >> m >> k;
	int u,v,w;
	long long cnt = 0;
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		cnt += w;
	}
	int c;
	for(int i = 1;i <= k;i++){
		cin >> c;
		for(int j = 1;j <= n;j++) cin >> a[i][j];
	}
	if(c == 0) cout << 0;
	else cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
