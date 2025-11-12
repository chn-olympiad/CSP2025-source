#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 110;
int n, m, cnt, x = 1, y = 1;

struct node{
    int mark, id;
}marks[N * N];

bool cmp(node a, node b){
    return a.mark > b.mark;
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n * m;i ++) {
        cin >> marks[i].mark;
        marks[i].id = i;
    }

    sort(marks + 1, marks + n * m + 1, cmp);

    while(cnt <= n * m){
        cnt ++;
        int tx = x, ty = y;
        if(y % 2 == 0){
            tx = x - 1;
            ty = y;
            if(tx < 1){
                tx ++;
                ty ++;
            }
        }else{
            tx ++;
            ty = y;
            if(tx > n){
                tx --;
                ty ++;
            }
        }
        x = tx, y = ty;
        if(marks[cnt + 1].id == 1) break;
    }

    cout << y << " " << x << "\n";
    return 0;
}
