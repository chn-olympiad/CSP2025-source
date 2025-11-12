#include <bits/stdc++.h>
using namespace std;
long long a[10000001];
int main (){
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long tot = n * m;
	for (int i = 1; i <= tot; i++){
		scanf ("%lld", &a[i]);
	}
	long long aaa = a[1];
	long long level = 1;
	for (long long i = 2; i <= tot; i++){
		if (a[i] > aaa){
			level++;
		}
	}
	long long m1;
	if (level % n == 0){
		m1 = level / n;
	} else {
		m1 = level / n + 1;
	}
	long long bbb = (m1 - 1) * n;
	long long wei = level - bbb;
	long long n1;
	if (m1 % 2 == 0){
		n1 = n - wei + 1;
	} else {
		n1 = wei;
	}
	cout << m1 << " " << n1;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
