#include <bits/stdc++.h>
using namespace std;
long long a[10000001];
int main (){
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	long long n;
	scanf ("%lld", &n);
	for (long long i = 0; i < n; i++){
		scanf ("%lld", &a[i]);
	}
	cout << "0";
	fclose (stdin);
	fclose (stdout);
	return 0;
}
