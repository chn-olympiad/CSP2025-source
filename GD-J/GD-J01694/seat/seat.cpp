#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[105], b[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int r = a[1], x = n * m;
	sort(a + 1, a + n * m + 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			b[i][j] = a[x];
			x--;
		}
		i++;
		for(int j = m; j > 0; j--){
			b[i][j] = a[x];
			x--;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(b[i][j] == r) cout << i << ' ' << j << endl;
		}
	}
	return 0;
}
