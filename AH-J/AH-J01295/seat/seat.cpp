#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, x, rp = 0, h, l, yu, a[N];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    x = a[1];
    sort(a + 1, a + n * m + 1);
    for(int i = n * m; i >= 1; i--){
        rp++;
        if(x == a[i]){
            break;
        }
    }
    l = (rp + n - 1) / n;
    yu = rp - n * (l - 1);
    if(l % 2 == 0){
        h = n - yu + 1;
    }else{
        h = yu;
    }
    cout << l << " " << h;
    return 0;
}
