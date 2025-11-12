#include<bits/stdc++.h>
using namespace std;
int n, k, a[500001], res;
bool b = 1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(a[i] != 1) b = 0;
	}
	if(b && k == 0){
		cout << n / 2;
		return 0;
	}
	int tmp = -1; 
	for(int i = 1; i <= n; i ++){
		if(tmp == -1) tmp = a[i];
		else tmp = (tmp ^ a[i]);
		if(tmp == k){
			tmp = -1;
			res ++;
		}
	}
	cout << res;
	return 0;
}
