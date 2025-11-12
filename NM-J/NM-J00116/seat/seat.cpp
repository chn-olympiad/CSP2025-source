#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
bool cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    int r = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int turn = 0;    //down 0 right 1 up 2
    int x = 1, y = 1;
    for(int i = 1;i <= n * m;i++){
        if(a[i] == r){
            cout << x << " " << y << '\n';
            return 0;
        }
        if(turn == 0){
            y++;
            if(y == n){
                turn = 1;
            }
        }else if(turn == 1){
            x++;
            if(y == n){
                turn = 2;
            }else{
                turn = 0;
            }
        }else{
            y--;
            if(y == 1){
                turn = 1;
            }
        }
    }
    return 0;
}
//expect:100pts
