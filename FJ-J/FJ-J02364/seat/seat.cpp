#include<bits/stdc++.h>

using namespace std;

int n, m, a[110], c[11][11], k;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d", &a[i]);
	}k = a[1];
	sort(a + 1, a + n * m + 1);
	for(int x = 1, i = n * m; x <= m; x++){
		if(x % 2 == 1){
			for(int y = 1; y <= n; y++){
				c[x][y] = a[i--];
			}
		}
		else{
			for(int y = n; y >= 1; y--){
				c[x][y] = a[i--];
			}
		}
	}for(int x = 1; x <= m; x++){
		for(int y = 1; y <= n; y++){
			if(c[x][y] == k){
				printf("%d %d\n", x, y);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}