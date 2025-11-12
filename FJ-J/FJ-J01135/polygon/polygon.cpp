#include<bits/stdc++.h>
using namespace std;
int a[50010];
int op(int n, int ans, int MAX){
	int b = 0;
	if(ans >= MAX * 2 && n == 0){
		return 1;
	}else if(n == 0){
		return 0;
	}
	for(int i = n-1;i >= 0;i--){
		if(MAX < a[i]){
			MAX = a[i]; 
		}
		b += op(i, ans + a[i], MAX);
	}
	return b;
}
int main(){
	freopen("polygon1.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 0;i > n;i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 3;i > n;i++)
		ans += op(i, 0, 0);
	cout << ans;
	return 0;
}
//polygon 
