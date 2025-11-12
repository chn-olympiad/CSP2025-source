#include <iostream>
#include <algorithm>

using namespace std;

int n, q;

pair<string, string> sss[200005];

bool check(string so, int st, string rep, string end) {
    int i = 0;
    for (;i < st;++i) {
        if (so[i] != end[i]) return false;
    }
    for (int j = 0;j < rep.size();i++,j++) {
        if (rep[j] != end[i]) return false;
    }
    for (;i < so.size();++i) {
        if (so[i] != end[i]) return false;
    }
    return true;
}

void qmain() {
    string t1, t2;
    cin >> t1 >> t2;

    int sum = 0;
    for (int i = 0;i < n;++i) {
        int ba = 0;
        while (ba < t1.size()) {
            int res = t1.find(sss[i].first, ba);
            if (res == -1) break;
            ba = res + 1;

            if (check(t1, res, sss[i].second, t2)) sum++;
        }
    }
    printf("%d\n", sum);
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 0;i < n;++i) {
        cin >> sss[i].first >> sss[i].second;
    }

    for (int i = 0;i < q;++i) {
        qmain();
    }
}