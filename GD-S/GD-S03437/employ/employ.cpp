#include <bits/stdc++.h>
using namespace std;
const long long N = 998244353;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long s = 1;
	long long k = 1;
	for (int i = 100; i >= 54; i--){
		s = s * i;
		s = s % N;
	}
	cout << s;
	for (int j = 47; j >= 1; j--){
		k = k * j;
		k = k % N;
	}
	cout << (s / k) % N;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
