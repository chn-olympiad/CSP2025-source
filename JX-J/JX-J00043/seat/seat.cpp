#include <bits/stdc++.h>
using namespace std;

int a[10000];

bool cmp(int a , int b) {
    return a > b;
}

int main() {
    int n,m;
    freopen("seat.in" , "r" ,stdin);
    freopen("seat.out" , "w" , stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) {
        cin>>a[i];
    }
    int k = a[1] , p = 0;
    sort(a + 1 , a + n * m + 1 , cmp);
    bool flog = true;
    for (int j=1;j<=m;j++) {
        if (flog == false) break;
        if (j % 2 == 1) {
            for (int i=1;i<=n;i++) {
                p ++;
                if (a[p] == k) {
                    cout<<j<<" "<<i;
                    flog = false;
                    break;
                }
            }
        }else {
            for (int i=n;i>=1;i--) {
                p ++;
                if (a[p] == k) {
                    cout<<j<<" "<<i;
                    flog = false;
                    break;
                }

            }
        }
    }
    return 0;
}
