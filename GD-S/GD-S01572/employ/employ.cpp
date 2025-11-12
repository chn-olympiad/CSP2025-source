#include <iostream>
#include <algorithm>
using namespace std;
int c[505], perm1[505];
int main() {
	freopen("employ.in", "r", stdin); 
	freopen("employ.out", "w", stdout);
	
	int n, m, cnt = 0;
	cin >> n >> m;
	string dif;
	cin >> dif;
	for (int i = 0; i < n; i++) cin >> c[i], perm1[i] = i;
	do {
		int fai = 0, lu = 0;
		for (int i = 0; i < n; i++) {
			if (fai >= c[perm1[i]]) {
				fai++;
				continue;
			}
			if (dif[i] == '0') fai++;
			else {
				lu++;
			} 
		}
		if (lu >= m) cnt++;
		if (cnt == 998244353) cnt = 0; 
	} while (next_permutation(perm1, perm1 + n));
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
