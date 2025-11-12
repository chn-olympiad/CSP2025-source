#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N], b[N][N];

bool cmp(int x, int y){
	return x > y;
}

int main(){
//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m); 
	for(int i = 1; i <= n*m; i++){
		scanf("%d", &a[i]);
	}
	int rj = a[1];
	
	sort(a+1, a+n*m+1, cmp);
	
	bool f = 1;
	int g = 1;
    for(int i = 1; i <= m; i++){
    	if(f == 1){
    		f = 0;
    		for(int j = 1; j <= n; j++){
    			b[j][i] = a[g];
    			g++;
			}
		}else{
			f = 1;
			for(int j = n; j >= 1; j--){
				b[j][i] = a[g];
				g++;
			}
		}
	}
	for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(b[i][j] == rj){
    			printf("%d %d", j, i);
    			return 0;
			}
		}
	}
	return 0;
}
