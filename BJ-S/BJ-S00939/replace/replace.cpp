#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<map>
using namespace std;

int n, q, ll, lbound, rbound, ans;
multimap<string, string> s;
multimap<string, string>::iterator it;
string ss1, ss2, t1, t2;
bool flag;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> ss1 >> ss2;
        s.insert(make_pair(ss1, ss2));
    }
    for (int i = 1;i <= q;i++) {
        ans = 0;
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << 0 << endl;
            continue;
        }
        ll = t1.size();
        for (lbound = 0;lbound <= ll - 1 && t1[lbound] == t2[lbound];lbound++);
        for (rbound = ll - 1;rbound >= 0 && t1[rbound] == t2[rbound];rbound--);
        for (int x = 0;x <= lbound && x <= ll - 1;x++) {
            for (int z = max(x, rbound);z <= ll - 1;z++) {
                it = s.find(t1.substr(x, z - x + 1));
                if (it != s.end()) {
                    if (it->second == t2.substr(x, z - x + 1))
                        ans += s.count(t1.substr(x, z - x + 1));
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
