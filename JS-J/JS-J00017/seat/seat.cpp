#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int n, m;
int a[N * N + 5];
bool cmp(int x, int y){
    return x > y;
}
signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    int s = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1; i <= n * m; i++){
        if(a[i] == s){
            //cout << i << " ";
            int l = (i + n - 1) / n;
            int k = i % n;
            if(k == 0) k = n;
            int h;
            if(l % 2 == 1){
                h = k;
            }else{
                h = n - k + 1;
            }
            cout << l << " " << h;
            break;
        }
    }
    return 0;
}
