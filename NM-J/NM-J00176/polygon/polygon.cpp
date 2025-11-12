#include <bits/stdc++.h>
using namespace std;

int n, l[5005];

long long fact(int p){
	if (p <= 1) return 1;
	return (p*fact(p-1))%998244353;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> l[i];
	}
	long long res=0;
	for (int i = 3; i <= n; i++){
//		cout << fact(n)/fact(n-i)/fact(i) << ' ' << res << ' ' << fact(n)/fact(n-i)/fact(i)<< endl;
		res += fact(n)/(fact(n-i)*fact(i));
		res %= 998244353;
	}
	cout << res;
	return 0;
} 
