#include <bits/stdc++.h>
using namespace std;

int rd[1000001][4] ={};
int cyrd[11][1001] ={};
int cy[11] ={};
int n, m, k;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) cin >> rd[i][1] >> rd[i][2] >> rd[i][3];
	for(int i = 1; i <= k; i++) {
		cin >> cy[i];
		for(int j = 1; j <= n; j++) cin >> cyrd[i][j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
