#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5, M = 1e12;
ll n, k, a[N], ans;
struct node {
    int start, end1;
};
vector<node> an;
bool cmp(node a, node b) {
    if (a.end1 != b.end1) return a.end1 < b.end1;
    return a.start > b.start;
}
void dfs(int i, int z, int st) {
    cout << i << " " << z << ' ' << st << "\n";
    if (z == k) {
        node a;
        a.start = st;
        a.end1 = i - 1;
        an.push_back(a);
    }
    if (i == n) return;
    dfs(i + 1, z ^ a[i], st);
    if (i != 0) dfs(i + 1, a[i], i);
}
int main() {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    scanf("%lld %lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    dfs(0, 0, 0);
    sort(an.begin(), an.end(), cmp);
    int t = 0, last_s = -1, last_e = -1;
    for (int i = 0; i < an.size(); i++) {
        if (t <= an[i].start && an[i].end1 != last_e && an[i].start != last_s) {
            ans++;
            t = an[i].end1;
            last_s = an[i].start, last_e = an[i].end1;
        }
    }
    cout << ans;
    return 0;
}
