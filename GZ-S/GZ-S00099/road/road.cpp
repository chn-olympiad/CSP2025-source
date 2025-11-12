//GZ-S00099 贵阳市第一中学 周代岳
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0,mp[10020][10020],f[10020];
int find(int a,int b,int c){
	f[a] = 1;
	if(mp[a][b] == 0) {
		return 0;	
	}	
	int minab=mp[a][b];
	for(int i=0;i<n+k;i++){
		if(mp[a][i] < minab && f[i] == 0){
			f[i] = 1;
			if(minab> find(i,b,0) + mp[a][i]){
				minab = find(i,b,0)+mp[a][i];
			}
			else{
				f[i] = 0;
			}
		}
	}
	if(c){
		mp[a][b] = mp[b][a]= 0;
	}
	return minab;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=0;i<n+k;i++){
		for(int j=0;j<n+k;j++){
			mp[i][j] = 900000000;
		}
	}
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		mp[u][v] = mp[v][u] = w;
	}
	for(int i=0;i<k;i++){
		int c;
		cin >> c;
		for(int j=0;j<n;j++){
			int w;
			cin >> w;
			mp[n+i][j] = mp[j][n+i] = w+c;
		}
	}	
	for(int i=1;i<n;i++){
		memset(f,0,sizeof(f));
		ans += find(0,i,1);
		cout << ans << endl;
	}
	cout << ans;
	return 0;
}
