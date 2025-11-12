#include <bits/stdc++.h>
#define ARR_MAX 112333
#define IOFILE "replace"

using namespace std;

long long n, q; // num for sp, num for query
pair<string, string> sp[ARR_MAX];
pair<string, string> qp;

int main() {
    freopen(IOFILE".in", "r", stdin);
    freopen(IOFILE".out", "w", stdout);
    
    cin >> n >> q;
    for (long long i = 1; i <= n; i++) {
        cin >> sp[i].first >> sp[i].second;
    }
    for (long long j = 1; j <= q; j++) {
        cin >> qp.first >> qp.second;

    } 
    while (true) {
        printf("hello wolrd");
    }


    return 0;
}