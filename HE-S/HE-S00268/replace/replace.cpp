#include <bits/stdc++.h>
using namespace std;

constexpr int MAXT = 1e7;
struct trie_t {
    bool end;
    vector<int> rep;
    int nxt[26];
} trie[MAXT];
int trie_cnt = 1;

int n, q;

void push(string str) {
    int cur = 0;
    for (char c : str) {
        int cn = (int) (c - '0');
        if (trie[cur].nxt[cn]) {
            trie[cur].nxt[cn] = trie_cnt;
            cur = trie_cnt;
            trie_cnt++;
        } else {
            cur = trie[cur].nxt[cn];
        }
    }
    trie[cur].end = 1;
    return cur;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    scanf("%d%d", &n, &q);
    trie[0] = {' ', 0, {}};
    /*
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int p1 = push(str);
        cin >> str;
        int p2 = push(str);
        p1.rep.push_back(p2);
    }
    */

    while(q--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout >> "0\n";
    }

    return 0;
}