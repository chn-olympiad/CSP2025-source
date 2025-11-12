#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int T;
int n;

struct node {
    int val, d;
};

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

inline bool cmp(node x, node y) {
    return x.val > y.val;
}

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	T = read();

	while(T--) {
        n = read();
        int cnt[4];
        priority_queue<int> p[4];
        memset(p, 0, sizeof(p));
        int top[4];
        top[1] = top[2] = top[3] = 0;
        int ans = 0;
        cnt[1] = cnt[2] = cnt[3] = 0;
        for(int i = 1; i <= n; ++i) {
            node x[4];
            for(int j = 1; j <= 3; ++j) {
                x[j].val = read();
                x[j].d = j;
            }
            sort(x + 1, x + 3 + 1, cmp);
            ++cnt[x[1].d];
            // ++cnt[x[2].d];
            ans += x[1].val;
            p[x[1].d].push(x[2].val - x[1].val);
        }
        int maxx = max(cnt[1], max(cnt[2], cnt[3]));
        if(maxx <= n / 2) {
            writeln(ans);
        }
        else {
            if(cnt[1] == maxx) {
                // sort(p[1] + 1, p[1] + top[1] + 1);
                for(int i = 1; i <= maxx - n / 2; ++i) {
                    ans += p[1].top();
                    p[1].pop();
                }
            }
            else if(cnt[2] == maxx) {
                // sort(p[2] + 1, p[2] + top[2] + 1);
                for(int i = 1; i <= maxx - n / 2; ++i) {
                    ans += p[2].top();
                    p[2].pop();
                }
            }
            else if(cnt[3] == maxx) {
                // sort(p[3] + 1, p[3] + top[3] + 1);
                for(int i = 1; i <= maxx - n / 2; ++i) {
                    ans += p[3].top();
                    p[3].pop();
                }
            }
            writeln(ans);
        }
	}

    return 0;
}
