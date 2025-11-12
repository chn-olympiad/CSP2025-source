#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, k;
int a[N];
int sum;
void solve(int l){
	for(int i = l; i <= n; i++){
		int x = a[l];
		for(int j = l+1; j <= i; j++) x ^= a[j];
		if(x == k){
			sum++;
			solve(i+1);
			return;
		}
	}
	return;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	solve(1);
	cout << sum;
	return 0;
}
