#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

inline int read() {
    int x = 0, w = 1; char c = getchar();
    while (!isdigit(c)) { if (c == '-') w = -w; c = getchar(); }
    while (isdigit(c)) { x = (x << 3) + (x << 1) + c - 48; c = getchar(); }
    return x * w;
}

inline void write(int x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}

int n;
int q;
string s1;
string s2;
vector<vector<int>> KMP;
vector<string> S;
vector<string> S2;
vector<ull> H1;
vector<ull> H2;
ull P[5000005];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    n = read(), q = read();

    P[0] = 1;

    for (int i = 1; i <= 5000000; i++)
        P[i] = P[i - 1] * 131;

    for (int i = 1; i <= n; i++) {
        cin >> s1 >> s2;
        int l = s1.length();
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        vector<int> kmp;
        kmp.push_back(0);
        kmp.push_back(0);
        for (int j = 2; j <= l; j++) {
            int k = kmp[j - 1];
            while (k && s1[k + 1] != s1[j])
                k = kmp[k];
            if(s1[k + 1] == s1[j])
                kmp.push_back(k + 1);
            else
                kmp.push_back(0);
        }
        ull hash1 = 0;
        for (int j = 1; j <= l; j++)
            hash1 = hash1 * 131 + s1[j] - 'a';
        H1.push_back(hash1);
        hash1 = 0;
        for (int j = 1; j <= l; j++)
            hash1 = hash1 * 131 + s2[j] - 'a';
        H2.push_back(hash1);
        KMP.push_back(kmp);
        S.push_back(s1);
        S2.push_back(s2);
    }

    while (q--) {
        cin >> s1 >> s2;
        if (s1.length() != s2.length()) {
            puts("0");
            continue;
        }
        int l = s1.length();
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        ull hash1 = 0, hash2 = 0;
        for (int j = 1; j <= l; j++) {
            hash1 = hash1 * 131 + s1[j] - 'a';
            hash2 = hash2 * 131 + s2[j] - 'a';
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l2 = S[i].length() - 1;
            for (int j = 1, k = 0; j <= l; j++) {
                while (k && S[i][k + 1] != s1[j])
                    k = KMP[i][k];
                if (S[i][k + 1] == s1[j])
                    k++;
                if (k == l2) {
                    ans += (hash1 + (H2[i] - H1[i]) * P[l - j] == hash2);
                    k = KMP[i][k];
                }
            }
        }
        write(ans);
        puts("");
    }

    return 0;
}
