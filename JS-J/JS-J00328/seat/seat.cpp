#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int tmp;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
        if(i == 1) tmp = a[i];
    }
    sort(a + 1, a + n * m + 1);
    int t;
    for(int i = n * m;i > 0;i--){
        if(a[i] == tmp){
            t = n * m - i + 1;
            break;
        }
    }
    int ans1 = t / n + 1;
    int ans2 = t % n;
    if(ans1 % 2 == 0){
        if(ans2 == 0) cout << ans1 - 1 << ' ' << 1 << endl;
        else cout << ans1 << ' ' << m - ans2 + 1 << endl;
        return 0;
    }
    if(ans2 == 0) cout << ans1 - 1 << ' ' << m << endl;
    else cout << ans1 << ' ' << ans2 << endl;
    return 0;
}
