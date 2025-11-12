#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
constexpr int N = 5e5 + 10;

int n, k;
int a[N];
int x[N];
struct node {
    int b, e;
    void setnode(const int& nb, const int& ne) { b = nb, e = ne; }
    bool operator<(const node& cmp) {
        if (e != cmp.e) return e < cmp.e;
        return b > cmp.b;
    }
};
unordered_map<int, int> mp;
vector<node> vec;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        x[i] = a[i] ^ x[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if ((x[j] ^ x[i - 1]) == k) {
                if (mp.find(j) == mp.end()) mp[j] = i;
                else if (mp[j] < i) mp[j] = i;
            }
        }
    }
    node tmp;
    for (pair<int, int> it : mp) {
        tmp.setnode(it.second, it.first);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    int ed, cnt; ed = cnt = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].b <= ed) continue;
        ed = vec[i].e;
        ++cnt;
    }
    cout << cnt << endl;
	return 0;
}
