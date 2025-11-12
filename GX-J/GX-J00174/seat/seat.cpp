#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],x,z,l,r;
bool flag = false;
int main(){
    freopen("w","seat.in",stdin);
    freopen("r","seat.out",stdout);
    cin >> n >> m,l = r = 1;
    for (int i = 1;i <= n * m;i++) cin >> a[i];
    z = a[1];
    sort(a + 1,a + n * m + 1);
    for (int i = 1;i <= n * m / 2;i++) swap(a[i],a[n * m - i + 1]);
    for (int i = 1;i <= n * m;i++) if (a[i] == z) x = i;
    for (int i = 1;i < x;i++){
        if (!flag){
            if (l == n) r++,flag = true;
            else l++;
        } else {
            if (l == 1) r++,flag = false;
            else l--;
        }
    }
    cout << r << " " << l;
    return 0;
}
