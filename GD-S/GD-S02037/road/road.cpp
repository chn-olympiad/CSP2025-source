#include<bits/stdc++.h>
using namespace std;
int arr[1005][1005];
int aee[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin >> n >> m >> k;
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		arr[u][v];
		ans += w;
	}
	while(k--){
		int c;
		cin >> c;
		for(int i = 1;i <= n;i++){
			cin >> aee[i];
		}
		
	} 
	cout << ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
