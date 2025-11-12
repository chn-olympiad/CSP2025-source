

#include <iostream>
#include <vector>

#define int long long

using namespace std;

const int MAXN = 2e5 + 9, MAXS = 5e6 + 9;
const int mod = 998244353, p = 30;
int n, q;
string s1[MAXN], s2[MAXN];
string t1[MAXN], t2[MAXN];

int idS1[MAXN], idS2[MAXN], idT1, idT2;

int power[MAXS];
int hs1[MAXN], hs2[MAXN];
vector<int> ht1[MAXN];
int ht2[MAXN];

int Get (int i, int l, int len) {
    if (len == 0) return 0;

    int r = l + len - 1;

    int one = ht1[i][r];
    int two;
    if (l == 0) two = 0;
    else two = ht1[i][l - 1];

    return (one - two * power[len] % mod + mod) % mod;
}

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    power[0] = 1;
    for (int i = 1; i <= 5e6; i++) power[i] = power[i - 1] * p % mod;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i], hs1[i] = 0;
        for (int j = 0; j < s1[i].length(); j++)
            hs1[i] = (hs1[i] * p % mod + (s1[i][j] - 'a' + 1)) % mod;

        cin >> s2[i], hs2[i] = 0;
        for (int j = 0; j < s2[i].length(); j++)
            hs2[i] = (hs2[i] * p % mod + (s2[i][j] - 'a' + 1)) % mod;
    }

    bool flag = 1;
    if (q != 1) flag = 0;
    if (flag) {
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 0; j < s1[i].length(); j++) {
                if (s1[i][j] != 'a' && s1[i][j] != 'b') flag = 0;
                if (s1[i][j] == 'b') cnt++, idS1[i] = j;
            }
            if (cnt != 1) {
                flag = 0;
                break;
            }

            cnt = 0;
            for (int j = 0; j < s2[i].length(); j++) {
                if (s2[i][j] != 'a' && s2[i][j] != 'b') flag = 0;
                if (s2[i][j] == 'b') cnt++, idS2[i] = j;
            }
            if (cnt != 1) {
                flag = 0;
                break;
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        cin >> t1[i];
        int num = 0;
        for (int j = 0; j < t1[i].length(); j++) {
            num = (num * p % mod + (t1[i][j] - 'a' + 1)) % mod;
            ht1[i].push_back(num);
        }

        cin >> t2[i], ht2[i] = 0;
        for (int j = 0; j < t2[i].length(); j++)
            ht2[i] = (ht2[i] * p % mod + (t2[i][j] - 'a' + 1)) % mod;

        if (flag) {
            int cnt = 0;
            for (int j = 0; j < t1[i].length(); j++) {
                if (t1[i][j] != 'a' && t1[i][j] != 'b') flag = 0;
                if (t1[i][j] == 'b') cnt++, idT1 = j;
            }
            if (cnt != 1) flag = 0;

            cnt = 0;
            for (int j = 0; j < t2[i].length(); j++) {
                if (t2[i][j] != 'a' && t2[i][j] != 'b') flag = 0;
                if (t2[i][j] == 'b') cnt++, idT2 = j;
            }
            if (cnt != 1) flag = 0;

            if (flag) {
                int cnt = 0;
                for (int j = 1; j <= n; j++) {
                    if (t1[i].length() - s1[j].length() + s2[j].length() != t1[i].length()) {
                        continue;
                    }
                    if (idS1[j] - idS2[j] != idT1 - idT2) {
                        continue;
                    }
                    if (idT1 >= idS1[j] && t1[i].length() - idT1 >= s1[j].length() - idS1[j]) {
                        cnt++;
                    }
                }
                cout << cnt << '\n';
            }

            return 0;
        }

        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < (int)t1[i].length() - (int)s1[j].length() + 1; k++) {
//                if (t1[i].substr(k, s1[j].length()) == s1[j]) {
//                    string str = t1[i].substr(0, k);
//                    str += s2[j];
//                    str += t1[i].substr(k + (int)s1[j].length(), t1[i].length() - k - (int)s1[j].length());
//                    if (str == t2[i]) cnt++;
//                }
                if (Get(i, k, s1[j].length()) == hs1[j]) {
//                    cout << "test ";
//                    cout << i << ',' << j << ',' << k << ' ';
//                    cout << Get(i, k, s1[j].length()) << ',' << hs1[j] << endl;
                    int str = Get(i, 0, k);
//                    cout << str << ' ';
                    str = (str * power[s2[j].length()] % mod + hs2[j]) % mod;
//                    cout << str << ' ';
                    int len = t1[i].length() - k - (int)s1[j].length();
                    str = (str * power[len] % mod + Get(i, k + (int)s1[j].length(), len)) % mod;
//                    cout << str << "   ";
//                    cout << ht2[i] << endl;
//                    cout << "len = " << len << ' ' << i <<',' << k + (int)s1[j].length() << endl;
                    if (str == ht2[i]) cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
