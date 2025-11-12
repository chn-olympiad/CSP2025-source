#include<bits/stdc++.h>
using namespace std;
int n , a[5005] , cnt = 0 , b[5005];
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)cin >> a[i];
	if(n == 3){
		if(a[1] + a[2] + a[3] > 2 * max(max(a[1] , a[2]) , a[3]))cout << 1;
		else cout << 0;
		return 0;
	}
	else{
		for(int i = 4; i <= n; i ++)cnt += ((i - 3) * (i - 2) / 2) , cnt %= 998244353;
		cout << cnt;
		return 0;
	}
	return 0;
}