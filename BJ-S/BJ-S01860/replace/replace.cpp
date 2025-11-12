

#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
#define PII pair<int, int>

using namespace std;

const int P1 = 0x7f6f5f4f;
const int P2 = 1e9 + 9;
const int D = 31;
int N, Q;
map<PII, PII> mp;
struct Node {
    int s[26];
    vector<int> id;
} e;
vector<Node> tr;
int Read () {
    int x = 0; char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return x;
}
void Read (char s[], int &n) {
    char c = getchar();
    while (c < 'a' || c > 'z') c = getchar();
    while (c >= 'a' && c <= 'z') s[++n] = c - 'a', c = getchar();
}
char s1[2500009], s2[2500009];
void Insert (int &x, char c) {
    if (!tr[x].s[c]) tr.push_back(e), tr[x].s[c] = tr.size() - 1;
    x = tr[x].s[c];
}
int lst[200009], ln;
bool vis[200009];
int main () {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n;
    int l, r;
    int p1, p2, r1, r2;
    PII t;
    for (int i = 0; i < 26; i++) e.s[i] = 0;
    e.id.clear();
    tr.push_back(e);
    N = Read(), Q = Read();
    for (int i = 1; i <= N; i++) {
        n = 0, Read(s1, n), n = 0, Read(s2, n);
        l = -1;
        for (int j = 1; j <= n; j++)
            if (s1[j] != s2[j]) {l = j; break;}
        if (l == -1) continue;
        for (int j = n; j; j--)
            if (s1[j] != s2[j]) {r = j; break;}
        p1 = p2 = 0;
        for (int j = l; j <= r; j++) p1 = (1ll * p1 * D + s1[j] + 1) % P1, p2 = (1ll * p2 * D + s2[j] + 1) % P2;
        PII &t = mp[{p1, p2}];
        if (!t.first) {
            tr.push_back(e), t.first = tr.size() - 1;
            tr.push_back(e), t.second = tr.size() - 1;
        }
        r1 = t.first, r2 = t.second;
        for (int j = l - 1; j; j--) Insert(r1, s1[j]);
        for (int j = r + 1; j <= n; j++) Insert(r2, s2[j]);
        tr[r1].id.push_back(i), tr[r2].id.push_back(i);
    }
    int n1, n2;
    int ans;
    while (Q--) {
        n1 = 0, n2 = 0;
        Read(s1, n1), Read(s2, n2);
        if (n1 != n2) puts("0");
        else {
            n = n1;
            for (int j = 1; j <= n; j++)
                if (s1[j] != s2[j]) {l = j; break;}
            for (int j = n; j; j--)
                if (s1[j] != s2[j]) {r = j; break;}
            p1 = p2 = 0;
            for (int j = l; j <= r; j++) p1 = (1ll * p1 * D + s1[j] + 1) % P1, p2 = (1ll * p2 * D + s2[j] + 1) % P2;
            t = mp[{p1, p2}];
            r1 = t.first, r2 = t.second;
            if (!r1) puts("0");
            else {
                for (int v : tr[r1].id)
                    if (!vis[v]) vis[v] = true, lst[++ln] = v;
                for (int j = l - 1; j; j--) {
                    r1 = tr[r1].s[s1[j]];
                    if (!r1) break;
                    for (int v : tr[r1].id)
                        if (!vis[v]) vis[v] = true, lst[++ln] = v;
                }
                ans = 0;
                for (int v : tr[r2].id)
                    if (vis[v]) ans++;
                for (int j = r + 1; j <= n; j++) {
                    r2 = tr[r2].s[s1[j]];
                    if (!r2) break;
                    for (int v : tr[r2].id)
                        if (vis[v]) ans++;
                }
                for (int j = 1; j <= ln; j++) vis[lst[j]] = 0;
                ln = 0;
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}