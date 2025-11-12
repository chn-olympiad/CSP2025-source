#include<bits/stdc++.h>
using namespace std;
int ma[10001][10001];
int panduan[10001]={0};
int ap[10001];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u, v, w;
		cin >> u >> v >> w;
		ma[u][v]=w;
		ma[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin >> c;
		for(int j=1;j<=n;j++){
			int a;
			cin >> a;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ma[i][j]!=0){
				panduan[i]=1;
				panduan[j]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	cout << ans << endl;
	return 0;
}
