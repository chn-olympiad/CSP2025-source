#include <iostream>
using namespace std;
const int N = 505, MOD = 998344353;
long long f(int n){
	long long ans = 1;
	for(int i = 1; i <= n; i++){
		ans = (ans * i) % MOD;
	}
	return ans;
}
int main(){
	int n, m;
	cin >> n >> m;
	string s;
	int c;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> c;
	}
	cout << f(n) << endl;
	return 0;
}
