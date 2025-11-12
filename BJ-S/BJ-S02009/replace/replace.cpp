#include <iostream>
#include <string>
#include <utility>
#include <map>
#define maxn 200005

int n, q;
std::pair<int, int> ch[maxn];
std::pair<std::string, std::string> s[maxn], t[maxn];
std::map<std::pair<std::string, std::string>, int> Map;
bool tbd(std::string s) {
    int cnt = 0;
    for (char c : s) {
        if (c != 'a') {
            if (c != 'b') return false;
            if (++cnt > 1) return false;
        }
    }
    if (cnt == 0) return false;
    return true;
}

bool check(int i, int j, int a, int b) {
    return ch[j].first <= a && s[j].first.size() - ch[j].first <= t[i].first.size() - a;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    std::cin >> n >> q;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i].first >> s[i].second;
        if (!tbd(s[i].first) || !tbd(s[i].second)) flag = 0;
    }
    for (int i = 1; i <= q; i++) {
        std::cin >> t[i].first >> t[i].second;
        if (!tbd(t[i].first) || !tbd(t[i].second)) flag = 0;
    }
    if (flag) {
        for (int i = 1; i <= n; i++) ch[i] = {s[i].first.find('b'), s[i].second.find('b')};
        for (int i = 1; i <= q; i++) {
            int a = t[i].first.find('b'), b = t[i].second.find('b');
            long long ans = 0;
            for (int j = 1; j <= n; j++) if (ch[j].first - ch[j].second == a - b && check(i, j, a, b)) ++ans;
            std::cout << ans << "\n";
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) Map[{s[i].first, s[i].second}]++;
    for (int i = 1; i <= q; i++) {
        long long ans = 0;
        std::string a = "", b = "";
        int n = t[i].first.size();
        for (int l = 0; l < n; l++) {
            a = "", b = "";
            int st = n - 1;
            while (t[i].first[st] == t[i].second[st]) --st;
            for (int k = l; k < st; k++) a += t[i].first[k], b += t[i].second[k];
            for (int k = st; k < n; k++) {
                a += t[i].first[k], b += t[i].second[k];
                ans += Map[{a, b}];
            }
            if (t[i].first[l] != t[i].second[l]) break;
        }
        std::cout << ans << "\n";
    }
    return 0;
}
