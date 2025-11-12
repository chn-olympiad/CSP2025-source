#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#define ll long long

using namespace std;

const int NR = 2e5 + 10;
const ll mod = 1e9 + 7;
const ll B = 97;
vector<char> s1[NR], s2[NR];

void read(vector<char> &str) {
    char x = getchar();
    int cnt = 0;
    while(x < 'a' || x > 'z') {
        //if(++cnt <= 10) printf("%d\n", x);
        x = getchar();
    }
    while('a' <= x && x <= 'z') {
        str.push_back(x);
        x = getchar();
    }
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        read(s1[i]);
        read(s2[i]);
    }
    while(q--) {
        vector<char> t1, t2;
        read(t1);
        read(t2);
        if(t1.size() != t2.size()) {
            puts("0");
            continue;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int ls = s1[i].size(), lt = t1.size();
            for(int j = 0; j + ls - 1 < lt; j++) {
                vector<char> tmp = t1;
                bool fl = true;
                //printf("! %d\n", ls);
                for(int k = 0; k < ls; k++) {
                    if(s1[i][k] != t1[j + k] || s2[i][k] != t2[j + k]) {
                        fl = false;
                        break;
                    }
                    tmp[j + k] = t2[j + k];
                }
                if(tmp != t2) fl = false;
                if(fl) ans++;
                if(fl) break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
