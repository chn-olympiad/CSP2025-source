#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int b[1000001];
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m , vis;
	cin >> n >> m;
	for(int i = 1; i<=n * m; i++) cin >> b[i];
	vis = b[1];
	int k = 1;
	sort(b + 1 , b + n * m + 1 , cmp);
	for(int i = 1; i<=m / 2 + 2; i+=2){
		for (int j = 1; j<=n; j++){
			a[j][i] = b[k];
			k++;
		}
		for (int j = n; j>=1; j--){
			a[j][i + 1] = b[k];
			k++;
		}
	}
	int x , y;
	for(int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (a[i][j] == vis){
				x = i , y = j;
				break;
			}
		}
	}
	cout << y << " " << x;
	return 0;
}
