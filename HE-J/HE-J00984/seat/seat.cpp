#include<bits/stdc++.h>
using namespace std;
int s[15][15];
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int sum = a[1];
	sort(a + 1, a+ n * m + 1);
	int x = 0;
	if(m % 2 != 0){
		x += 1;
	}
	for(int i = 1; i <= m; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++){
				s[j][i] = a[x];
				x++;
			}
		}else if(i % 2 == 0){
			for(int j= n; j > 1; j--){
				s[j][i] = a[x];
				x++;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j= 1; j<= n; j++){
			if(s[i][j] == sum){
				cout << i << " " << j;
			}
		}
	}
	return 0;
}
