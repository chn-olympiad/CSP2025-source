#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define read int

inline read rd() {
    int x = 0, f = 1, ch = getchar();
    for(; !isdigit(ch); ch = getchar()) {
        if(ch == '-') {
            f = -1;
        }
    }
    for(; isdigit(ch); ch = getchar()) {
        x = (x * 10) + (ch ^ 48);
    }
    return f * x;
}

const int N = 2e5 + 10;

int n, q;
string s1[N][3], s2[N][3];


int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    n = rd(); q = rd();

    for(int i = 1; i <= n; i++) {
        cin >> s1[i][1] >> s1[i][2];
    }
    
    for(int i = 1; i <= q; i++) {
        cin >> s2[i][1] >> s2[i][2];
    }

    for(int i=1; i <= q; i++) {
        int ans = 0;
        for(int j=1; j <= n; j++) {
            if(s1[i][1].substr(s2[j][1]) && s2[i][2].substr(s2[j][2])) {
                ans ++;
            }
        }
        cout<< ans << '\n';
    }
    

    return 0;
}

// LN-S00062