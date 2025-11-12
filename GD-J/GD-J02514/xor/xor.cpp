#include <iostream>
#include <algorithm>
#define MAXN (500010) 

using namespace std;
int n, K;
int xorr[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

	int ans = 0;
	cin >> n >> K;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a == K) {
			ans ++;
			continue;
		}
		if (xorr[i - 1] == K) continue;
		xorr[i] = xorr[i - 1] ^ a;
	}
	
	for (int i = 1; i <= n; i++) {
		if (xorr[i] == K)
			ans ++;
	}
	cout << ans << "\n";

    cout << flush;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
