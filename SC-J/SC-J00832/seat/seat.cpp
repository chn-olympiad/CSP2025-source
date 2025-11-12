#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int ans[11][11];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int r = a[1];
	int k = 0;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1;i <= m;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= n;j++){
				ans[i][j] = a[++k];
				if(ans[i][j] == r){
					cout << i << " " << j;
					return 0;
				}
			}
		}else{
			for(int j = n;j >= 1;j--){
				ans[i][j] = a[++k];
				if(ans[i][j] == r){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}