#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5+5;
ll a[N];

ll read(){
    ll s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9'){
        s *= 10;
        s += (ch - '0');
        ch = getchar();
    }
    return s * f;
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    ll n = read(), k = read(), xr = -1, cnt = 0, fr = 1;
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= n; ++i){
        if (xr == -1) xr = a[i], fr = i;
        else xr ^= a[i];

        if (xr == k) cnt += 1, xr = -1;
        else {
            ll tmp = xr;
            for (int j = fr; j < i; ++j){
                tmp ^= a[j];
                if (tmp == k){
                    cnt += 1, xr = -1;
                    break;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
