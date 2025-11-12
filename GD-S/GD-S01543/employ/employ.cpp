#include<bits/stdc++.h>
using namespace std;
int a[105];
int fun(int n){
	if (n==1) return 1;
	return n*fun(n-1);
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	string s;
	int n, m;
	cin >> n >> m;
	cin >> s;
	for (int i=1; i<=n; i++){
		cin >> a[i];
	}
	cout << fun(n) << '\n';
	return 0;
} 
