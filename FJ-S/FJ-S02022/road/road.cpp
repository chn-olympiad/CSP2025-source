#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	int m;
	int k;
	cin >> n;
	cin >> m;
	cin >> k;
	int a[n][m];
	int cost[m];
	int re[m];
	int sum;
	for (int i = 0;i<m;i++){
		cin >> a[i][0];
		cin >> a[i][1];
		cin >> cost[i];
	}
	for (int j = 0;j<m;j++){
		for (int l = 0;l<m;l++){
			if ((a[j][0] == a[l][0] && a[j][1] == a[l][1] ) || (a[j][0] == a[l][1] && a[j][0] == a[l][1]){
				if (cost[j] <= cost[l]){
					re[l] = 1;
				}
				if (cost[l] < cost[j]){
					re[j] = 1;
				}
			}
		}
	}
	for (int q = 0;q<m;q++){
		if(re[q] != 1){
			sum += cost[q];
		}
	}	
	cout << sum;
	return 0;
}
