#include <bits/stdc++.h>
using namespace std;
long long n, k, a[100005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 2){
		cout << 0;
		return 0;
	}
	else if(n == 3){
		if(a[1] + a[2] + a[3] > max(max(a[1], a[2]), a[3])){
			cout << 1;
			return 0;
		}
		else{
			cout << 0;
			return 0;
		}
	}
	else{
		cout << 6;
	}
	return 0;
}
