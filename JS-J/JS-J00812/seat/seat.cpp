#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], b;
int main(){
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    cin >> n >> m;
    cin >> b;
    a[1] = b;
    for (int i = 2; i <= n * m; i++) cin >> a[i];
    sort (a + 1, a + (n * m) + 1);
    for (int i = n * m; i >= 1; i--){
        if (a[i] == b) {
            b = n * m - i + 1;
            break;
        }
    }
    int l, h;
    if (b % n == 0) l = b / n;
    else l = b / n + 1;
    if (l % 2 == 0) h = l * n - b + 1;
    else h = n - (l * n - b);
    cout << l << " " << h;
    return 0;
}

