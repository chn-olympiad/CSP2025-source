#include<bits/stdc++.h>
using namespace std;
int n, m, k, a[10001][10001], nm, b[10001];
void build(int l, int r, int num){
	a[l][0]++;
	a[l][r] = num;
}
void bfs(int l, int b[], int num, int b1){
	int minn, min1 = 1e9+1;
	for(int i = 1; i <= b1; i++){
		for(int j = 1; j <= n; j++){
			int dream = 0;
			for(int sum = 1; sum <= b1; sum++){
				if(b[sum] == j){
					dream = 1;
					break;
				}
			}
//			cout << b[i] << " " << j << " " << a[b[i]][j] << endl;
			if(dream == 0 && min1 > a[b[i]][j] && a[b[i]][j] != 0){
				min1 = a[b[i]][j];
				minn = j;
			}
		}
	}
	b1++;
	b[b1] = minn;
	num += min1;
//	for(int i = 1; i <= b1; i++){
//		cout << b[i] << " ";
//	}
//	cout << endl << num << endl;
	if(b1 == n){
		cout << num;
		return ;
	}
	bfs(minn, b, num, b1);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int z, x, d;
		scanf("%d%d%d", &z, &x, &d);
		build(z, x, d);
		build(x, z, d);
	}
	for(int i = 1; i <= k; i++){
		scanf("%d", &nm);
		for(int j = 1; j <= n; j++){
			scanf("%d", &nm, &nm);
		}
	}
	b[1] = 1;
	bfs(1, b, 0, 1);
	return 0;
}
