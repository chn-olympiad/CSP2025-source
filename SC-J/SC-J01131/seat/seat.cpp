#include<bits/stdc++.h>
using namespace std;
int a[200], n, m, ans, sum, x, y;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	ans = a[1];
	sort(a+1, a+n*m+1);
	for(int i = n*m; i >= 1; i--){
		sum++;
		if(a[i] == ans){
			break;
		}
	}
	x = sum/n;
	y = sum%n;
	//cout << x << ' ' << y << '\n';
	if(y == 0){
		cout << x << ' ';
		if(x%2 == 0){
		    cout << 1;
	    }else{
		    cout << n;
	    }
	    return 0;
	}else{
		cout << x+1 << ' ';
	}
	if((x+1)%2 == 0){
		cout << n-y+1;
	}else{
		cout << y;
	}
	return 0;
}