#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, m, R;
int room[N][N];
int marks[N * N];
bool cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; ++i) cin >> marks[i];
    R = marks[1];
    sort(marks + 1, marks + 1 + n * m, cmp);
    int cnt = 0;
    for(int j = 1; j <= m; ++j){
        if(j % 2){
            for(int i = 1; i <= n; ++i){
                room[i][j] = marks[++cnt];
            }
        } else{
            for(int i = n; i >= 1; --i){
                room[i][j] = marks[++cnt];
            }
        }
    }
    bool flag = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)
            if(room[i][j] == R){
                flag = 1;
                cout << j << " " << i;
                break;
            }
        if(flag) break;
    }
    return 0;
}
