#include<bits/stdc++.h>
using namespace std;
long long sum = 1;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x != 0){
			sum *= x;
			sum %= 998244353;
		}
	}
	cout << sum;
	return 0;
}

