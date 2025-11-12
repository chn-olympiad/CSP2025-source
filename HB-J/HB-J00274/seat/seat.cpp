#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    int l = a[1];
    sort(a + 1, a + 1 + n * m, greater<int>());
    int x = 1, y = 1;
    int idx = 1;
    bool u = true;
    while(a[idx++] != l){
        if(u){
            if(y == n) u = false, x++;
            else y++;
        }else{
            if(y == 1) u = true, x++;
            else y--;
        }
    }
    cout << x << " " << y;
    return 0;
}
