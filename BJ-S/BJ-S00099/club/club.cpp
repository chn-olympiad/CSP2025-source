#include <bits/stdc++.h>
using namespace std;

int t, n;
struct student {
    int a, b, c;
};

student stu[100005];

struct node {
    int id, now;
    bool operator > (const node other) const {
        if (now == 1) {
            return stu[id].a - max(stu[id].b, stu[id].c) > stu[other.id].a - max(stu[other.id].b, stu[other.id].c);
        } else if (now == 2) {
            return stu[id].b - max(stu[id].a, stu[id].c) > stu[other.id].b - max(stu[other.id].a, stu[other.id].c);
        } else {
            return stu[id].c - max(stu[id].b, stu[id].a) > stu[other.id].c - max(stu[other.id].b, stu[other.id].a);
        }
    }
};

priority_queue <node, vector <node>, greater<node> > q[4];
int score[4];

int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        memset(score, 0, sizeof(score));
        for (int i = 1; i <= 3; ++i) {
            while (!q[i].empty()) {
                q[i].pop();
            }
        }
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> stu[i].a >> stu[i].b >> stu[i].c;
            if (max(stu[i].a, max(stu[i].b, stu[i].c)) == stu[i].a) {
                score[1] += stu[i].a;
                q[1].push({i, 1});
            } else if (max(stu[i].a, max(stu[i].b, stu[i].c)) == stu[i].b) {
                score[2] += stu[i].b;
                q[2].push({i, 2});
            } else {
                score[3] += stu[i].c;
                q[3].push({i, 3});
            }
        }
        while (q[1].size() > (n / 2)) {
            node t = q[1].top();
            q[1].pop();
            score[1] -= stu[t.id].a;
            if (stu[t.id].b > stu[t.id].c) {
                score[2] += stu[t.id].b;
                q[2].push({t.id, 2});
            } else {
                score[3] += stu[t.id].c;
                q[3].push({t.id, 3});
            }
        }
        while (q[2].size() > (n / 2)) {
            node t = q[2].top();
            q[2].pop();
            score[2] -= stu[t.id].b;
            if (stu[t.id].a > stu[t.id].c) {
                score[1] += stu[t.id].a;
                q[1].push({t.id, 1});
            } else {
                score[3] += stu[t.id].c;
                q[3].push({t.id, 3});
            }
        }
        while (q[3].size() > (n / 2)) {
            node t = q[3].top();
            q[3].pop();
            score[3] -= stu[t.id].c;
            if (stu[t.id].b > stu[t.id].a) {
                score[2] += stu[t.id].b;
                q[2].push({t.id, 2});
            } else {
                score[1] += stu[t.id].a;
                q[1].push({t.id, 1});
            }
        }
        cout << score[1] + score[2] + score[3] << "\n";
    }
    return 0;
}
