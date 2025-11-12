#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, rk = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n*m; i ++) scanf("%d", &a[i]);
	for(int i = 2; i <= n*m; i ++)
		if(a[i] > a[1]) rk ++;
	int cx = 0, r = 1, c = 1;
	for(int i = 1; i < rk; i ++){
		if(cx % 2 == 0){
			if(r < n) r ++;
			else c ++, cx ++;
		}
		else{
			if(r > 1) r --;
			else c ++, cx ++;
		}
	}
	printf("%d %d", c, r);
	return 0;
}
