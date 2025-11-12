#include<bits/stdc++.h>
using namespace std;
int a[10010][10010],b[3];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= 3 ; j++){
				cin >> a[i][j];
			}
		}
		long long cnt = 0;
		for(int i = 1 ; i <= n ; i++){
			int q = -1,q1;
			for(int j = 1 ; j <= 3 ; j++){
				if(b[j] <= n / 2){
					if(q < a[i][j]){
						q = a[i][j];
						q1 = j;
					}
				}
			}
			cnt += q;
			b[q1]++;
		}
		cout << cnt;
		for(int i = 1 ; i <= 3 ; i++){
			b[i] = 0;
		}
	}
} 
