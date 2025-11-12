#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], x = 1, y = 1, z;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
	int v = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for(int i = 1; i <= n * m; i++){
		if(a[i] == v){
			printf("%d %d", y, x);
			return 0;
		}
		if(!z){
			x++;
			if(x > m) y++, z = 1, x = m;	
		}else{
			x--;
			if(x < 1) y++, z = 0, x = 1;
		}
	}
	return 0;
}
