#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
long long a[N][5];

struct node {
    long long now, mns, idx;
    bool operator<(const node &x) const {
        return mns < x.mns;
    }
};

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
	    int n;
        cin >> n;
        long long ret = 0;
        set<int> colA, colB, colC;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
            if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
                ret += a[i][0];
                colA.insert(i);
            } else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
                ret += a[i][1];
                colB.insert(i);
            } else if (a[i][2] >= a[i][0] && a[i][2] >= a[i][1]) {
                ret += a[i][2];
                colC.insert(i);
            }
        }
        if (colA.size() > n / 2) {
            priority_queue<node> q;
            for (auto it : colA) {
                q.push({it, a[it][1] - a[it][0], 1});
                q.push({it, a[it][2] - a[it][0], 2});
            }
            while (colA.size() > n / 2 && colB.size() < n / 2 && colC.size() < n / 2 && !q.empty()) {
                node f = q.top();
                q.pop();
                if (colA.count(f.now) != 0) {
                    ret += f.mns;
                    colA.erase(f.now);
                    if (f.idx == 1) {
                        colB.insert(f.now);
                    } else {
                        colC.insert(f.now);
                    }
                }
            }
            while (colA.size() > n / 2 && colB.size() < n / 2 && !q.empty()) {
                node f = q.top();
                q.pop();
                if (colA.count(f.now) != 0 && f.idx == 1) {
                    ret += f.mns;
                    colA.erase(f.now);
                    colB.insert(f.now);
                }
            }
            while (colA.size() > n / 2 && colC.size() < n / 2 && !q.empty()) {
                node f = q.top();
                q.pop();
                if (colA.count(f.now) != 0 && f.idx == 2) {
                    ret += f.mns;
                    colA.erase(f.now);
                    colC.insert(f.now);
                }
            }
        } else if (colB.size() > n / 2) {
            priority_queue<node> q;
            for (auto it : colB) {
                q.push({it, a[it][0] - a[it][1], 0});
                q.push({it, a[it][2] - a[it][1], 2});
            }
            while (colB.size() > n / 2 && colA.size() < n / 2 && colC.size() < n / 2 && !q.empty()) {
                node f = q.top();
                q.pop();
                if (colB.count(f.now) != 0) {
                    ret += f.mns;
                    colB.erase(f.now);
                    if (f.idx == 0) {
                        colA.insert(f.now);
                    } else {
                        colC.insert(f.now);
                    }
                }
            }
            while (colB.size() > n / 2 && colA.size() < n / 2 && !q.empty()) {
                node f = q.top();
                q.pop();
                if (colB.count(f.now) != 0 && f.idx == 0) {
                    ret += f.mns;
                    colB.erase(f.now);
                    colA.insert(f.now);
                }
            }
            while (colB.size() > n / 2 && colC.size() < n / 2 && !q.empty()) {
                node f = q.top();
                q.pop();
                if (colB.count(f.now) != 0 && f.idx == 2) {
                    ret += f.mns;
                    colB.erase(f.now);
                    colC.insert(f.now);
                }
            }
        } else if (colC.size() > n / 2) {
            priority_queue<node> q;
            for (auto it : colC) {
                q.push({it, a[it][0] - a[it][2], 0});
                q.push({it, a[it][1] - a[it][2], 1});
            }
            while (colC.size() > n / 2 && colA.size() < n / 2 && colB.size() < n / 2 && !q.empty()) {
                node f = q.top();
                q.pop();
                if (colC.count(f.now) != 0) {
                    ret += f.mns;
                    colC.erase(f.now);
                    if (f.idx == 0) {
                        colA.insert(f.now);
                    } else {
                        colB.insert(f.now);
                    }
                }
            }
            while (colC.size() > n / 2 && colA.size() < n / 2 && !q.empty()) {
                node f = q.top();
                q.pop();
                if (colC.count(f.now) != 0 && f.idx == 0) {
                    ret += f.mns;
                    colC.erase(f.now);
                    colA.insert(f.now);
                }
            }
            while (colC.size() > n / 2 && colB.size() < n / 2 && !q.empty()) {
                node f = q.top();
                q.pop();
                if (colC.count(f.now) != 0 && f.idx == 1) {
                    ret += f.mns;
                    colC.erase(f.now);
                    colB.insert(f.now);
                }
            }
        }
        cout << ret << "\n";
	}
	return 0;
}
