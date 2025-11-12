#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 * 5 + 5;

int numbers[MAXN], k, n, ans;

struct ListS {
    int starts, ends;
}answer[MAXN];

void dfs(int now, int sum, int starts) {
    if (sum == k) {
        ans++;
        answer[ans].starts = starts;
        answer[ans].ends = now;
        return ;
    }
    return ;
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> numbers[i];
    }
    for (int i = 1; i <= n; i++) {
        int starts = i, sum = numbers[i];
        if (numbers[i] == k) {
            ans++;
            answer[ans].starts = starts;
            answer[ans].ends = starts;
            continue;
        }
        for (int j = i + 1; j <= n; j++) {
            sum = sum ^ numbers[j];
            if (sum == k) {
                ans++;
                answer[ans].starts = starts;
                answer[ans].ends = j;
                break;
            }
        }
    }
    int cnt = 0, maxx = -1, l, r;
    for (int i = 1; i <= ans; i++) {
        cnt = 1;
        l = answer[i].starts;
        r = answer[i].ends;
        for (int j = 1; j <= ans; j++) {
            if ((r >= answer[j].starts && r <= answer[j].ends) || (l <= answer[j].ends && l >= answer[j].starts) || (l <= answer[j].starts && r >= answer[j].ends)) {
                continue;
            } else {
                cnt++;
                l = min(answer[j].starts, l);
                r = max(answer[j].ends, r);
            }
        }
        maxx = max(maxx, cnt);
    }
    cout << maxx;
    return 0;
}
