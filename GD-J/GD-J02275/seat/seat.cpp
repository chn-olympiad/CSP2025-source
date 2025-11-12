#include<bits/stdc++.h>
using namespace std;
int cmp(int x, int y){
    return x > y;
}
int n, m, a[105], ans, id;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; ++i){
        cin >> a[i];
        if(i == 1) ans = a[i];
    }
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1; i <= n * m; ++i)
        if(a[i] == ans) id = i;
    if(id % n != 0){
        cout << id / n + 1 << " ";
        if((id / n + 1) % 2 == 0) cout << n - (id % n) + 1;
        else cout << id % n;
    }
    else{
        cout << id / n << " ";
        if((id / n) % 2 == 0) cout << 1;
        else cout << n;
    }
    return 0;
}
