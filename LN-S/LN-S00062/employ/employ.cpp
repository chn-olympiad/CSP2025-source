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

const int N = 0;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    while(1) {
        cout<< "0\n";
    }

    return 0;
}

// LN-S00062