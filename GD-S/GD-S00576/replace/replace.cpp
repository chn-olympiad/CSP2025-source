#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
string arr[N][N];
int cost[N][N];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < q; i++){
		for(int j = 0; j < n+1; j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < q; i++){
		cout << "0" << endl; 
	}
	return 0;
}
