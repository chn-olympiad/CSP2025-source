// xor

#include <bits/stdc++.h>
#define ARR_MAX 500000
using namespace std;

long long n, val;
long long arr[ARR_MAX];
bool used[ARR_MAX];

long long ans;



long long doxor(long long l, long long r);
void setused(long long l, long long r);

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> val;

    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (long long l = 1; l <= n; l++) {
        for (long long r = l; r <= n; r++) {
            if (doxor(l, r) == val) {
                ans++;
                setused(l, r);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

long long doxor(long long l, long long r) {
    long long sum = 0;
    for (long long i = l; i <= r; i++) {
        if (used[i]) {
            return -1;
        } else {
            sum = sum xor arr[i];
        }
    }
    return sum;
}

void setused(long long l, long long r) {
    for (long long i = l; i <= r; i++) {
        used[i] = true;
    }
}