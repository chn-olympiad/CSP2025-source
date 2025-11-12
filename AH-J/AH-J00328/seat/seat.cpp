#include<bits/stdc++.h>
using namespace std;
long long a[110];
long long n, m, R, id;
bool cmp(long long a, long long b){return a > b;}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	R = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= m; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++){
				if(a[i * n - n + j] == R){
					cout << i << " " << j;
					return 0; 
				}
			}
		}
		else{
			for(int j = n, k = 1; j >= 1; j--, k++){
				if(a[i * n - n + k] == R){
					cout << i << " " << j;
					return 0; 
				}
			}
		}
	}
	return 0;
}
