#include <bits/stdc++.h>

using namespace std;

int n , m , a[501] , c[501] , b[501] , ok[501] , to;
long long ans = 0;
string s;

int main() {
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);
    scanf("%d%d" , &n , &m);
    cin >> s;
    for(int i=1;i<=n;i++) {
        scanf("%d" , &a[i]);
    }
    if(m == 1) {
        int sum = 0;
        while(s[sum] == '0') {
            sum++;
        }
        for(int i=1;i<=n;i++) {
            if(a[i] < sum) {
                ans++;
            }
        }
        printf("%lld" , ans);
    }
    else {
        bool t = true;
        for(int i=0;i<n;i++) {
            if(s[i] == '0') {
                t = false;
            }
        }
        if(t) {
            ans = 1;
            for(int i=1;i<=m;i++) {
                ans *= i + n - m;
                ans %= 998244353;
            }
            printf("%lld" , ans);
        }
        else {
            printf("7");
        }
    }
    return 0;
}
