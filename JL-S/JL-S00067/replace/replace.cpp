#include <bits/stdc++.h>
using namespace std;

int n, q;
map<int, pair<char[5000010], char[5000010]>> s;
map<int, int> cha;
char t[2][5000010];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%s%s", s[i].first + 1, s[i].second + 1);
        int pos1, pos2, len1 = strlen(s[i].first + 1), len2 = strlen(s[i].second + 1);
        for (int j = 1; j <= len1; j++)
            if (s[i].first[j] == 'b') {
                pos1 = j;
                break;
            }
        for (int j = 1; j <= len2; j++)
            if (s[i].second[j] == 'b') {
                pos2 = j;
                break;
            }
        cha[pos2 - pos1]++;
    }
    while (q--) {
        scanf("%s%s", t[0] + 1, t[1] + 1);
        int pos1, pos2, len1 = strlen(t[0] + 1), len2 = strlen(t[1] + 1);
        for (int j = 1; j <= len1; j++)
            if (t[0][j] == 'b') {
                pos1 = j;
                break;
            }
        for (int j = 1; j <= len2; j++)
            if (t[1][j] == 'b') {
                pos2 = j;
                break;
            }
        printf("%d\n", cha[pos2 - pos1]);
    }
    return 0;
}
