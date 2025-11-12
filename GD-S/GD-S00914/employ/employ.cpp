#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PIL = pair<i64 , i64>;
const int N = 1e6 + 10 , Mod = 998244353;
mt19937_64 rng(time(0));
int mian(){
	cout << rng() % Mod;
	return 0;
}
int main(){
//	freopen("employ.in" , "r" , stdin);
//	freopen("employ.out" , "w" , stdout);
	i64 t = 1;
//	cin >> t;
	while(t--)mian();
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

