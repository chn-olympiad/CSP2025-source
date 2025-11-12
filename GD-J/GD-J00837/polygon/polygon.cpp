#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
int a[5010];
bool ch_prime[5010];
void solve() {
    int prime1[5010] = { }, prime2[5010] = { };
    long long ans = 0;
    for(int i = 3; i <= n - 1; i++) {
        for(int j = n; j >= n - i + 1; j--) {
            if(ch_prime[j]) {
                prime1[j]++; continue;
            }
            else {
                int t = j;
                for(int k = 2; k * k <= t; k++) {
                    while(ch_prime[k] && t % k == 0) {
                        t /= k;
                        prime1[k]++;
                    }
                }
                if(t != 1) prime1[t]++;
            }
        }
        for(int j = 2; j <= i; j++) {
            if(ch_prime[j]) {
                prime2[j]++; continue;
            }
            else {
                int t = j;
                for(int k = 2; k * k <= t; k++) {
                    while(ch_prime[k] && t % k == 0) {
                        t /= k;
                        prime2[k]++;
                    }
                }
                if(t != 1) prime2[t]++;
            }
        }
        long long tk = 1;
        for(int j = 2; j <= n; j++) {
            prime1[j] = prime1[j] - prime2[j];
            prime2[j] = 0;
            if(prime1[j] == 0) continue;
            tk *= j * prime1[j];
            prime1[j] = 0;
        }
        ans = (ans + tk) % MOD;
        tk = 1;
    }
    cout <<(ans + 1) % MOD;
}
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    for(int i = 1; i <= 5000; i++) {
        if(i == 1) ch_prime[i] = false;
        else if(i == 2) ch_prime[i] = true;
        else if(i % 2 == 0) ch_prime[i] = false;
        bool fl = false;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                fl = true; break;
            }
        }
        if(!fl) ch_prime[i] = true;
        else ch_prime[i] = false;
    }
    cin >>n;
    bool fl = true; //true: all are 1; false : all aren't 1;
    for(int i = 1; i <= n; i++) {
        cin >>a[i];
        if(a[i] != 1) fl = false;
    }
    if(fl == true && n > 3) {
        solve();
    }
    else {
        if(n == 1) cout <<"0";
        else if(n == 2) cout <<"0";
        else if(n == 3) {
            if(a[1] + a[2] + a[3] > max(max(a[1], a[2]), a[3]) * 2) {
                cout <<"1";
            }
            else cout <<"0";
        }
    }
    return 0;
}

