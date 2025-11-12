#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 1e6 + 7;

int n, m, a[201], r, now;

bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n * m; ++i) cin >> a[i];
	
	r = a[1];
	 
	sort(a + 1, a + 1 + n * m, cmp);
	
	for(int j = 1, k = 1; j <= m; ++j){
		if(j % 2 == 1){
			for(int i = 1; i <= n; ++i){
				if(a[k] == r){
					cout << j << " " << i;
					return 0;
				}
				k++;
			}
		}else{
			for(int i = n; i >= 1; --i){
				if(a[k] == r){
					cout << j << " " << i;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
