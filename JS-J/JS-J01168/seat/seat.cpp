#include <bits/stdc++.h>
using namespace std;
long long n, m, a[205], c, r, ans;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n*m; i++)
        cin >> a[i];
    int x = a[1];
    sort(a+1, a+n*m+1);
    for (int i = 1; i <= n*m; i++){
        if (a[i]==x){
            ans = n * m - i + 1;
            break;
        }
    }
    if (ans % n == 0){
        c = ans / n;
        if (c % 2 == 0)
            r = 1;
        else
            r = m;
    }
    else{
        c = ans / n + 1;
        if (c % 2 == 0){
            r = m + 1;
            r -= ans % n;
        }
        else
            r = ans % n;
    }
    cout << c << " " << r;
    return 0;
}
