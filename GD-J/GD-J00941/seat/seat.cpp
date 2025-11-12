#include<bits/stdc++.h>
using namespace std;
int n, m, a[103], g, l, s[103][103], x;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++){
		scanf("%d", &a[i]);
	}
	x = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int i = 1, j = 1;
	while(1){
		if(i > n){
			break;
		}
		if(g == 0){
			if(j > m){
				j = n;
				i++;
				g = 1;
				l++;
				s[i][j] = a[l];
				j--;
			}else{
				l++;
				s[i][j] = a[l];
				j++;
			}
		}else if(g == 1){
			if(j < 1){
				j = 1;
				i++;
				g = 0;
				l++;
				s[i][j] = a[l];
				j++;
			}else{
				l++;
				s[i][j] = a[l];
				j--;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i][j] == x){
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	return 0;
}
