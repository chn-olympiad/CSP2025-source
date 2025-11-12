#include <bits/stdc++.h>
using namespace std;
int n,m,a[500],x,y,cnt;
bool flag = false;
bool cmp(int p1,int p2) {
    return p1 > p2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n*m;i++) cin >> a[i];
    int r = a[1];
    sort(a+1,a+n*m+1,cmp);
    for (x = 1;x <= m;x++) {
        if (x % 2 == 1) {
            for (y = 1;y <= n;y++) {
                if (a[++cnt] == r){
                    flag = true;
                    break;
                }
            }
        } else {
            for (y = n;y >= 1;y--) {
                if (a[++cnt] == r){
                    flag = true;
                    break;
                }
            }
        }
        if (flag) break;
    }
    cout << x << " " << y;
    return 0;
}
