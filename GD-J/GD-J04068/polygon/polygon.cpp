#include <bits/stdc++.h>
using namespace std;

int n, a[5005], arr[5005];

bool cmp(int xx, int yy){
	return xx < yy;
}

int main(){
	freopen("polygon.in",  "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n, cmp);
	for (int i = 1; i <= n; i++){
		arr[i] = a[i] + arr[i-1];
	}
	for (int i = n-1; i >= 0; i--){
		
	}
	return 0;
}
