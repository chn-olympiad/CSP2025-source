#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[11][11], b[105], ki;
bool cmp(int x, int y){
	return x > y;
}
signed main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
 	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> b[i];
		if(i == 1){
			ki = b[i];
		}
	}
	sort(b+1, b+n*m+1, cmp);
	int i = 1, j = 1, k = 1;
	while(b[k] != ki){
		if(j % 2 == 1 && i != n){
			i++;
		}else if(j % 2 == 1 && i == n){
			j++;
		}else if(j % 2 == 0 && i != 1){
			i--;
		}else{
			j++;
		}
		k++;
	}
	cout << j << " " << i;
	return 0;
}