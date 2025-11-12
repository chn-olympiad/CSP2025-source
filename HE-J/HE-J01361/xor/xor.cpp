#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[500005], n, k;
int main(){
	long long ma=0;
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		ma += a[i];
	}
	if(k==1) cout << ma;
	else cout << n-ma;
	return 0;
}
