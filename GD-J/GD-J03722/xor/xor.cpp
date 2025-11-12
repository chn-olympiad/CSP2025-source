#include <bits/stdc++.h>
using namespace std;

int num[500001];
bool flag[500001];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, m; cin >> n >> m;
    map<pair<int, int>, int> sum;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // clog << "i";
        for (int j = i; j <= n; ++j) {
            // clog << "j";
            int xans = 0;
            auto it = sum.find(pair<int, int>(i, j));
            if (it != sum.begin()) {
            	for (auto& p : sum) {
            		clog << p.first.first << " " << p.first.second << " " << p.second << endl; 
				} 
            	clog << num[i] << " " << num[j] << "ÃüÖÐ»º´æ£º" << it->second << endl;
                xans = it->second;
            } else {
                for (int k = i; k <= j; ++k) {
                     clog << "k" << endl;
                    xans ^= num[k];
            		clog << num[i] << " " << num[j] << "Î´ÃüÖÐ»º´æ¡£" << endl;
                    sum.insert(pair<pair<int, int>, int>(pair<int, int>(i, k), xans));
                }
            }
            if (xans == m) ans ++;
        }
    }
    cout << ans;
}
