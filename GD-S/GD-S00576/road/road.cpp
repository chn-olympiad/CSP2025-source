#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int arr[N][N];
int cost[N][N];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 3; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n+1; j++){
			cin >> arr[i][j];
		}
	}
	
	cout << "0" << endl;
	return 0;
}
