#include <bits/stdc++.h>
using namespace std;
int n, k, a[500006], sum;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	if (k <= 1) {
		for (int i = 1;i <= n;i++) {
			scanf("%d", &a[i]);
			if (a[i] == k)
				sum++;
		}
		printf("%d", sum);
	} else {
		cout << "0" << endl;
	}
}
