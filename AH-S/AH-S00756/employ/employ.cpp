#include <bits/stdc++.h>
using namespace std;

int n, m;
int s[1010];
int c[1010];
int a[1010];
bool tag[1010];
int ret = 0;

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

inline void cal() {
    int now = 0;
    int tot = 0;
    for(int i = 1; i <= n; ++i) {
        if(!s[i])
            ++now;
        else {
            if(now >= c[a[i]]) {
                ++now;
            }
            else {
                ++tot;
            }
        }
    }
    if(tot >= m) {
        ++ret;
    }
}

inline void dfs(int cnt) {
    if(cnt == n + 1) {
        cal();
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if(!tag[i]) {
            a[cnt] = i;
            tag[i] = 1;
            dfs(cnt + 1);
            tag[i] = 0;
        }
    }
}

int main() {
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

    n = read();
    m = read();

    char str[1010];
    scanf("%s", str + 1);
    for(int i = 1; i <= n; ++i) {
        s[i] = (str[i] == '1');
        // cout << s[i] << ' ';
    }
    for(int i = 1; i <= n; ++i) {
        c[i] = read();
    }

    dfs(1);

    writeln(ret);

    return 0;
}
