#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string x;
	cin >> x;
	char a[1000005];
	ll tj=0;
	for (ll i=0; i<x.size(); i++){
		if (x[i] >= '0' && x[i] <= '9'){
			a[tj] = x[i];
			tj++;
		}
	}
	for (ll i=9; i>=0; i--){
		for (ll j=0; j<tj; j++){
			if (a[j] == char(i+'0')){
				cout << a[j];
			}
		}
	}
	return 0;
}
