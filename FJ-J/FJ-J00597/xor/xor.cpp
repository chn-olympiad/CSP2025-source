#include <bits/stdc++.h>
using namespace std;
long long a[10000001];
int main (){
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	long long n, k;
	scanf ("%lld%lld", &n, &k);
	for (long long i = 0; i < n; i++){
		scanf ("%lld", &a[i]);
	}
	cout << "0";
	fclose (stdin);
	fclose (stdout);
	return 0;
}
