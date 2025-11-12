#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
        if(!(i - 1)){
            k = a[i];
        }
    }
    sort(a + 1,a + n * m + 1);
    for(int i = 1;i <= n * m;i++){
        if(a[i] == k){
            s = n * m - i + 1;
            break;
        }
    }
    cout << (s - 1) / n + 1 << ' ' << (((((s - 1) / n + 1) % 2 * 2 - 1) * ((s - 1) % n + !(((s - 1) / n + 1) % 2)) + !(((s - 1) / n + 1) % 2) * n + 1) - 1) % n + 1;
    return 0;
}
