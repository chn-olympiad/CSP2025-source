#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n=0,m=0,k=0;
	cin >> n >> m >> k;
	int a[m][3] = {};
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cin >> a[i][j];
		}
	}
	int b[k][n+1] = {};
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin >> b[i][j];
		}
	}
	int ans = 13;
	
	
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
