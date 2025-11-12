#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1e5 + 9;
const int M = 9;

int a[N][M];
struct Node {
    int big, small, val;
};
vector<int> A;
vector<Node> Ace;
vector<Node> Boy;
vector<Node> Dog;
vector<int> inA, inB;

bool spjA(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (a[i][j]) return 0;
        }
    }
    return 1;
}

bool cmp(Node a, Node b) {
    return a.val < b.val;
}

bool spjB(int n, int m) {
    for (int i = 1; i <= n; i++) {
        //for (int j = 2; j <= m; j++) {
            int j = 3;
            if (a[i][j]) return 0;
        //}
    }
    return 1;
}

long long Origino = -0x3f3f3f3f;
void dfs(int i, int n, long long val, int p1, int p2, int p3) {
    if (i == n + 1) {
        Origino = max(Origino, val);
        return;
    } if (p1 + 1 <= n / 2) {
        dfs(i + 1, n, val + a[i][1], p1 + 1, p2, p3);
    } if (p2 + 1 <= n / 2) {
        dfs(i + 1, n, val + a[i][2], p1, p2 + 1, p3);
    } if (p3 + 1 <= n / 2) {
        dfs(i + 1, n, val + a[i][3], p1, p2, p3 + 1);
    } return;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        A.clear();
        Ace.clear();
        Boy.clear();
        Dog.clear();
        inA.clear();
        inB.clear();
        Origino = -0x3f3f3f3f;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                scanf("%d", &a[i][j]);
            }
        } 
        if (spjA(n, 3))
        {
            // How to get.it... ..
            for (int i = 1; i <= n; i++) {
                int j = 1;
                A.push_back(a[i][j]);
            } sort(A.begin(), A.end());
            long long ans = 0;
            for (int i = A.size() - 1; i >= (A.size() + 1) / 2; i--) {
                ans += (long long)A[i];
            }
            printf("%lld\n", ans);
        }
        else if (spjB(n, 3)) {
            for (int i = 1; i <= n; i++) {
                int x = a[i][1], y = a[i][2];
                if (x > y) {
                    Ace.push_back({x, y, x - y});
                }
                if (x < y) {
                    Boy.push_back({y, x, y - x});
                }
                if (x == y) {
                    Dog.push_back({x, y, 0});
                }
            }
            sort(Ace.begin(), Ace.end(), cmp);
            sort(Boy.begin(), Boy.end(), cmp);
            int len1, len2, len3;
            len1 = len2 = len3 = n / 2;
            while (!Ace.empty()) {
                if (len1>0) {
                    inA.push_back(Ace.back().big);
                    Ace.pop_back();
                    len1--;
                }
                else {
                    inB.push_back(Ace.back().small);
                    Ace.pop_back();
                    len2--;
                }
            }
            while (!Boy.empty()) {
                if (len2>0) {
                    inB.push_back(Boy.back().big);
                    Boy.pop_back();
                    len2--;
                }
                else {
                    inA.push_back(Boy.back().small);
                    Boy.pop_back();
                    len1--;
                }
            }
            while (!Dog.empty()) {
                if (len1>0) {
                    inA.push_back(Dog.back().big);
                    Dog.pop_back();
                    len1--;
                }
                else {
                    inB.push_back(Dog.back().small);
                    Dog.pop_back();
                    len2--;
                }
            }
            long long ans = 0ll;
            for (auto c : inA) {
                ans += c;
            }
            for (auto c : inB) {
                ans += c;
            }
            printf("%lld\n", ans);
        }
        else {
            dfs(1, n, 0ll, 0, 0, 0);
            printf("%lld\n", Origino);
        }
    }
    return 0;
}