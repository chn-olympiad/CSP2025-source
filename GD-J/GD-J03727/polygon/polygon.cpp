#include<bits/stdc++.h> 
using namespace std;
const int maxn = 5005;
int a[maxn],ans;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			for (int k = j + 1;k <= n;k++) {
				if (a[i] + a[j] + a[k] > 2 * (max(max(a[i],a[j]),a[k]))) ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
