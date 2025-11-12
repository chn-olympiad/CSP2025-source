#include<bits/stdc++.h>
using namespace std;

const int md = 998244353;
const int maxn = 505;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m, a[505], cnt = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0)
            cnt++;
    }
    int p = n-m-cnt+1;
    if(p > 0) {
        p = n;
        int temp = 1;
        while(true) {
            temp *= p;
            temp %= md;
            p--;
            if(p == 0) {
                cout << temp << endl;
                break;
            }
        }
    }
    else {
        cout << 0 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
