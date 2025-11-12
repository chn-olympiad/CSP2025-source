#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N]; 
int b[N][N];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int cnt = n * m;
    for(int i = 1; i <= n * m; i++)  cin >> a[i];
	int ans = a[1], sum = 0;
	sort(a + 1, a + cnt + 1, cmp);
	for(int i = 1; i <= n * m; i++)
		if(a[i] == ans) sum = i;
	int num = 1;
	for(int i = 1; i <= n; i++) b[i][1] = i;
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= m; j++){
			if(j % 2 != 0) {
				b[i][j] = b[i][j - 1] + num;
			}else {
				b[i][j] = b[i][j - 1] + (2 * n - num);
			}
	    }
		num += 2;  
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
		    if(sum == b[i][j]){
		    	cout << j << ' ' << i;
		    	return 0;
			} 
		}
	} 
	return 0;
}

