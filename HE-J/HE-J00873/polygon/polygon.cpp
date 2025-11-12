#include<bits/stdc++.h>
using namespace std;
int n,Max;
int a[5010];
long long sum;
long long ans;
int main() {
	freopen("polygon.in""w""stdin");
	freopen("polygon.out""r""stdout");
	cin >> n;
	for(int i = 0;i <= n;i++) {
		cin >> a[i];
		Max = max(a[i],Max);
		sum += a[i];
	}
	if(sum > Max * 2) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
}
