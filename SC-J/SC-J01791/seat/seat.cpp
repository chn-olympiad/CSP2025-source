#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
bool cmp(int x , int y){
	return x > y;
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	int a[n * m + 1] = {};
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int t = a[1];
	int k = 1;
	sort(a + 1 , a + 1 + n * m , cmp);
	int s[n + 1][m + 1] = {};
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= m; j++){
				if(a[k] == t){
					cout << i << " " << j;
					return 0;
				}
				s[i][j] = a[k];
;				k++;
			}
		}else{
			for(int j = m; j >= 1; j--){
				if(a[k] == t){
					cout << i << " " << j;
					return 0;
				}
				s[i][j] = a[k];
				k++;
			}
		}
	}
	return 0;
}