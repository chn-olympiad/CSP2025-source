// polygon

#include <bits/stdc++.h>
#define ARR_MAX 114514
using namespace std;


// no opening long long, can see fatherest and motherest
long long n;
long long lens[ARR_MAX];
bool visited[ARR_MAX];

long long path[ARR_MAX]; // for dfs
long long plen; // path length

long long ans;

bool _polyable(); // for dfs
void dfs(long long lev);


int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> lens[i];
    }

    dfs(0);

    cout << (ans % 998244353L) << endl;
    
    return 0;
}

bool _polyable() { // for dfs
    if (plen < 3) {
        return false;
    }
    long long sum = 0;
    long long maxl = -1;
    for (long long i = 1; i <= plen; i++) {
        sum += path[i];
        if (path[i] > maxl) { // find max length
            maxl = path[i];
        }
    }
    return (sum > (2 * maxl));
}

void dfs(long long lev) {
    // lev (level) is no used yet
    if (_polyable()) {
        ans++;
        return;
    }
    for (long long i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            plen++;
            path[plen] = lens[i];

            dfs(lev + 1);

            plen--; // ~= terminal -> rm
            visited[i] = false;
        }
    }
}