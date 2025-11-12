

#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

struct club{
    int a, b, c;
};
club num[100009], bf[100009];
int dp[100009];
int T, n;

bool cmp (club x, club y) {
    return x.a > y.a;
}

int res = 0;
void dfs (int x, int cc, int q, int w, int e) {
    if (x == n + 1) {
        res = max(res, cc);
        return;
    }
    if (q < n / 2) {
        dfs(x + 1, cc + num[x].a, q + 1, w, e);
    }
    if (w < n / 2) {
        dfs(x + 1, cc + num[x].b, q, w + 1, e);
    }
    if (e < n / 2) {
        dfs(x + 1, cc + num[x].c, q, w, e + 1);
    }
    
    
}

void ParseIn () {
    ifstream inFile("club.in");
    ofstream outFile("club.out");
    inFile >> T;
    while (T--) {
        inFile >> n;
        bool ok = 0;
        for (int i = 1; i <= n; i++) {
            inFile >> num[i].a >> num[i].b >> num[i].c;
            if (num[i].b != 0 || num[i].c != 0) {
                ok = 1;
            }
        }
        if (!ok) {
            sort(num + 1, num + n + 1, cmp);
            int cc = 0;
            for (int i = 1; i <= n / 2; i++) {
                cc += num[i].a;
            }
            outFile << cc << endl;
            continue;
        }
        dfs(1, 0, 0, 0, 0);
        outFile << res << endl;
        res = 0;
    }
    inFile.close();
    outFile.close();
}

int main () {
    ParseIn();
}