#include<bits/stdc++.h>
using namespace std;
int n, m, r, idd;
int a[110];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
		if(i == 1) r = a[1];
	}
	sort(a+1, a+n*m+1, cmp);
	for(int i = 1; i <= n*m; i++){
		if(a[i] == r){
			idd = i;
		}
	}
	int l = ceil(idd/(n*1.0)), h = idd%n, rh;
	if(l%2 == 1){
		if(h == 0) rh = n;
		else rh = h;
	}else{
		if(h == 0) rh = 1;
		else rh = n-h+1;
	}
	cout << l  << " " << rh;
	return 0;
}
