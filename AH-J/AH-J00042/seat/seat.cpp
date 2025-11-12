#include<bits/stdc++.h>
using namespace std;

int n, m, ns, R, f = 0;
int a[101];

bool cmd(int &x, int &y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	ns = n * m;
	for(int i = 1 ; i <= ns ; i++)
		scanf("%d", &a[i]);
	R = a[1];
	sort(a + 1, a + ns + 1, cmd);
	for(int i = 1 ; i <= m ; i++){
		if(i % 2 == 1)
			for(int j = 1 ; j <= n ; j++){
				++f;
				if(a[f] == R){
					printf("%d %d", i, j);
					return 0;
				}
			}
		else{
			for(int j = n ; j >= 1 ; j--){
				++f;
				if(a[f] == R){
					printf("%d %d", i, j);
					return 0;
				}
			}
		}
	}
	return 0;
}
