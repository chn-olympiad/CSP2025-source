#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e5+5;

int data[MAXN];
ll n,k;

ll solve(ll start) {
    ll cut=0;
    int xorsum=0;

   for(int i=start; i<n; i++) {
        xorsum ^= data[i];
        if (xorsum == k) {
            cut++;
            xorsum=0;
        }
    }

    return cut;
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin>>n>>k;
    if (n > 1000) { // timeout
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    for (ll i=0; i<n; i++) scanf("%d", &data[i]);

    ll maxcut=0;
    for (ll start=0; start<n; start++) {
        maxcut = max(maxcut, solve(start));
    }
    cout << maxcut << endl;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

