#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct clubnode {
    int va, idl;
};

bool cmp(clubnode a, clubnode b) {
    return a.va > b.va;
}

bool quecmp(clubnode a, clubnode b) {
    return a.va < b.va;
}

short t;
bool bl, bk;
long long n;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        bl = 0;
        int idl, sumf = 0, sumq = 0;
        cin >> n;
        int lp = n / 2;
        vector<vector<int>> bu(3);
        vector<vector<clubnode>> a(n, vector<clubnode>(3)), newa(3, vector<clubnode>(n));
        for (int i = 0; i < n; i++) {
            cin >> a[i][0].va >> a[i][1].va >> a[i][2].va;
            newa[0][i] = a[i][0], newa[1][i] = a[i][1], newa[2][i] = a[i][2];
            a[i][0].idl = 0, a[i][1].idl = 1, a[i][2].idl = 2;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                if (newa[i][j].va != 0) {
                    bk = 1;
                }
            }
            if (bk == 0) {
                break;
            }
        } if (!bk) {
            vector<queue<int>> ques(3);
            for (int i = 0; i < 3; i++) {
                sort(newa[i].begin(), newa[i].end(), quecmp);
                for (int j = 0; j < n; j++) {
                    ques[i].push(newa[i][j].va);
                }
            }
            for (int i = 0; i < 3; i++) {
                while(ques[i].size() > lp) {
                    ques[i].pop();
                }
            }
            for (int i = 0; i < 3; i++) {
                while (!ques[i].empty()) {
                    sumq += ques[i].front();
                    ques[i].pop();
                }
            }
            cout << sumq << "\n";
        } else {
            for (int i = 0; i < n; i++) {
                sort(a[i].begin(), a[i].end(), cmp);
                bu[a[i][0].idl].push_back(a[i][0].va);
            } for (int i = 0; i < 3; i++) {
                if (bu[i].size() <= lp) {
                    for (int j = 0; j < bu[i].size(); j++) {
                        sumf += bu[i][j];
                    }
                } else {
                    bl = 1;
                    break;
                }
            }
            if (!bl) {
                cout << sumf << "\n";
            }
        }
    }
    return 0;
}
