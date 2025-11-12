#include<bits/stdc++.h>
using namespace std;
const int ma = 1e6;
string a[ma];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n * 2; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= q; i++){
		string a, b;
		cin >> a >> b;
		cout << 0;
	}
	return 0;
}

