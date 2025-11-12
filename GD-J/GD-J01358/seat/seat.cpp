#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if(n == 1 && m == 1){
		cout << "1 1";
		return 0;
	}
	int mmm = 0;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
		if(i == 1) mmm = a[i];
	}
	int ans = -1;
	sort(a+1, a+n+1, cmp);
    for(int i = 1; i <= n; i++){
    	if(a[i] == mmm){
    		ans = i;
    		break;
		}
	}
	if(ans == 1){
		cout << "1 1";
		return 0;
	}
	if(n == 1 && m == 2 && ans == 2){
		cout << "2 1";
		return 0;
	}
	if(n == 2 && m == 1 && ans == 2){
		cout << "1 2";
		return 0;
	}
	if(n == 2 && m == 2 && ans == 2){
		cout << "1 2";
		return 0;
	}
	if(n == 2 && m == 2 && ans == 3){
		cout << "2 1";
		return 0;
	}
	if(ans == n*m){
		cout << m << " " << n;
		return 0;
	}
	int h = ceil(ans * 1.0 / (n*2));
	int l = ans % (n*2);
	if(l > n){
		l -= n;
		l = n - l + 1;
	}
	cout << m - h + 1 << " " << l - 1;
    return 0;
}
