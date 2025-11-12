#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int a[1010];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int s[n + 1][m + 1] = {0};
	for(int i = 1; i <= n * m; i ++){
		cin >> a[i];
	}
	int R = a[1];
	for(int i = 0; i <= n * m + n * m; i ++){
		int t = 0;
		for(int j = 1; j <= n * m; j ++){
			if(a[j] < a[j + 1]){
				swap(a[j],a[j + 1]);
				t ++;
			}
			if(t == 0){
				break;
			}
		}
	}
	int x = 1,y = 1;
	int k = 0;
	int num = 0;
	for(int i = 1; i <= n * m; i ++){
		if(k % 2 == 0){
			if(num + 1 < n){
				s[x ++][y] = a[i];
				num ++;
			}else{
				k ++;
				s[x][y ++] = a[i];
				num = 0;
			}
		}else{
			if(num + 1 < n){
				s[x --][y] = a[i];
				num ++;
			}else {
				k ++;
				s[x][y ++] = a[i];
				num = 0;
			}
		}
	}
	int c = 0,r = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j ++){
			if(s[i][j] == R){
				c = i;
				r = j;
				break;
			}
		}
	}
	cout << r << " " << c;
    return 0;
}
