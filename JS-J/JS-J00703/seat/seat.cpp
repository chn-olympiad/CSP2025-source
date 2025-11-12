#include <bits/stdc++.h>
using namespace std;

constexpr int N = 109;
int a[N];
int n, m, p;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) cin >> a[i];
    p = a[1];
    sort(a + 1, a + 1 + n * m, greater<int>());
    int c = 1, r = 0;//lie hang
    bool op = 0;
    for(int i = 1; i <= n * m; i++){
        if(!op){
            if(r != n) r++;
            else c++, op ^= 1;
        }
        else{
            if(r != 1) r--;
            else c++, op ^= 1;
        }
        //cout << a[i] << ' ' << c << ' ' << r << '\n';
        if(a[i] == p){
            cout << c << ' ' << r << '\n';
            return 0;
        }
    }
    return 0;
}
/*

2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92

*/