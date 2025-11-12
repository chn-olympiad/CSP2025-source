#include<iostream>
#include<cstring>
using namespace std;
const int N = 5e5 + 10,K = (1 << 20) + 10;
int n,k;
int a[N];
int sxor;
int lst[K];
int ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(lst,-1,sizeof(lst));
	lst[0] = 0;
	cin >> n >> k;
	for (int i = 1,j = 0; i <= n; i++) {
		cin >> a[i];
		sxor ^= a[i];
		if (lst[sxor ^ k] >= j) {
			ans++;
			j = i;
		}
		lst[sxor] = i;
	}
	cout << ans;
	return 0;
}
