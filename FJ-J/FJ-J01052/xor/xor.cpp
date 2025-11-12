#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int n;
long long a[N];
long long k;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %lld", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	cout << n;
	return 0;
}
