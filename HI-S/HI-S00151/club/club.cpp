#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
    cin >> t;
    while (t--) {
    ios::sync_with_stdio(false);
        int n;
    int 

        cin >> n;
        int m = n / 2;
		  vector<int,3>;
        for (int i = 0; i < n; ++i) {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        ll max_sum = 0;
        for (int x = 0; x <= m; ++x) {
            int y_min = max(0, n - x - m);
            int y_max = min(m, n - x);
            for (int y = y_min; y <= y_max; ++y) {
                vector<ll> s1, s2, s3;
                for (int &p : a) {
                    int a1 = p[0], a2 = p[1], a3 = p[2];
                    s1.push_back(a1);
                    s2.push_back(a2);
                    s3.push_back(a3);
                }
                sort(s1.rbegin(), s1.rend());
                ll sum = 0;
                for (int i = 0; i < x; ++i) sum += s1[i];
                vector<pair<ll, int>> tmp;
                for (int i = 0; i < n; ++i) {
                    tmp.emplace_back(s2[i], i);
                }
                sort(tmp.rv	begin(), tmp.rend());
                vector<bool> used(n, false);
                int cnt = 0;
                for (auto &[val, idx] : tmp) {
                    if (cnt >= y) break;
                    used[idx] = 1;
                    sum += val;
                    cnt++;
                }
                vector<ll> left;
                for (int i = 0; i < n; ++i) {
                    if (!used[i]) {
                        left.push_back(s3[i]);
                    }
                }
                sort(left.rbegin(), left.rend());
                for (ll val : left) sum += val;
                if (sum > max_sum) max_sum = sum;
            }
        }
        cout << max_sum << '\n';
    }
    
    return 0;
}
