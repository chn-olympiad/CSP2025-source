#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, a[105], sub;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1, a+1+n*m, cmp);
	for (int i = 1; i <= n*m; i++){
		if (a[i] == r){
			sub = i;
			break;
		}
	}
	int pd = sub / n; // ап 
	if (sub % n == 0){
		if (pd % 2 != 0){
			cout << sub / n << " " << n;
		}
		else{
			cout << sub / n << " " << 1;
		}
	}
	else{
		if ((pd + 1) % 2 != 0){
			cout << sub / n + 1 << " " << sub % n;
		}
		else{
			cout << sub / n + 1 << " " << n - sub % n + 1;
		}
	}
	
	return 0;
}
