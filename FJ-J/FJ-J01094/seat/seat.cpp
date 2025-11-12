#include <bits/stdc++.h>
using namespace std;
int s[105];
int a[105][105];
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n,m;
	cin >> n >> m;
	int cnt = n * m;
	for(int i = 0; i < cnt; i++){
		cin >> s[i];
	}
	int R = s[0];
	sort(s , s + cnt , greater<int>());
	int x = 1;
	int y = 1;
	int sum = 0;
	while(y <= m){
	    while(x <= n){
	    	if(y % 2 == 1){
	    	   a[x][y] = s[sum];
		       x++;
		       sum++;
			}else if(y % 2 == 0){
			   a[n + 1 - x][y] = s[sum];
		       x++;
		       sum++;
			}		     
	    }
	    y++;
	    x = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == R){
				cout << j << " " << i;
			}
		}
	}
	return 0; 
} 
