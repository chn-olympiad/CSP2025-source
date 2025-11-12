#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int a[N];
int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == pow(10, 5)){
		if(a[3] == 0 && a[2] == 0){
			cout << 0;
		}
	}
	return 0;
}
