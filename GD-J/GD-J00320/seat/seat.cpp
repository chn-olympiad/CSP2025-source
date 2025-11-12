#include <bits/stdc++.h>
using namespace std;
int n , m , a[20][20] , s[110];
void fun(int i , int j , int k){
	if(i != n || j != m){
		a[i][j] = s[k];
		if(j % 2 != 0){
			if(i + 1 > n) fun(i , j + 1 , k + 1);
			else fun(i + 1 , j , k + 1);
		}else{
			if(i - 1 < 1) fun(i , j + 1 , k + 1);
			else fun(i - 1 , j , k + 1);
		}
	}else a[i][j] = s[n * m];
}
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> s[i];
	int num = s[1];
	sort(s + 1 , s + n * m + 1);
	reverse(s + 1 , s + n * m + 1);
	fun(1 , 1 , 1);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(a[i][j] == num) cout << j << " " << i;
	return 0;
} 
