#include <fstream>
#include <algorithm>
#include <bitset>
using namespace std;

using ll = long long;
const int N = 1e5, M = 5e4;

int n;
int a[N], b[N], c[N];
ll f[M + 1]; 
bitset<M + 1> v{1};

ll dfs(int i, int na, int nb, int nc) {
    if(i == n) return 0;
    ll m = 0;
    if(na < n / 2) m = max(m, a[i] + dfs(i + 1, na + 1, nb, nc));
    if(nb < n / 2) m = max(m, b[i] + dfs(i + 1, na, nb + 1, nc));
    if(nc < n / 2) m = max(m, c[i] + dfs(i + 1, na, nb, nc + 1));
    return m;
}

int main() {
    ifstream in("club.in");
    ofstream out("club.out");
    int t; in >> t;
    while(t--) {
        in >> n;
        for(int i = 0; i < n; i++)
            in >> a[i] >> b[i] >> c[i];
        bool z = 1;
        for(int i = 0; i < n; i++) if(c[i]) z = 0;
        if(z) {
            fill(f, f + M + 1, 0); 
            for(int i = 1; i <= M; i++) v[i] = 0;
            for(int i = 0; i < n; i++) {
                for(int j = n / 2; j >= 1; j--) {
                    if(v[j]) f[j] += b[i];
                    if(v[j - 1]) {
                        f[j] = max(f[j], f[j - 1] + a[i]);
                        v[j] = 1;
                    }
                }
                if(v[0]) f[0] += b[i];
            }
            out << f[n / 2] << '\n';
            continue;
        }
        out << dfs(0, 0, 0, 0) << '\n';
    }
}
