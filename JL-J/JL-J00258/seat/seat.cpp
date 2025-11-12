#include<bits/stdc++.h>
using namespace std;

int f[15][15];
int s[105];

bool cmp(int a, int b) {
    return a > b;
}

int main() {

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    int R;
    scanf("%d%d", &n, &m);

    for(int i = 1;i <= n * m;i ++) {
        scanf("%d", &s[i]);
    }
    R = s[1];
    sort(s + 1, s + n * m + 1, cmp);

    //f[1][1] = s[1];
    int x = 1, y = 1;
    bool fx = 1;
    int ni = 1;
    while(ni <= n * m) {


        if(x > n) {
            x --;
            y ++;
            fx = !fx;
        }
        else if(x == 0){
            x ++;
            y ++;
            fx = !fx;
        }
        f[x][y] = s[ni];
        ni ++;
        if(f[x][y] == R) {
            printf("%d %d", y, x);
            return 0;
        }

        if(fx == 0) {
            x --;
        }else{
            x ++;
        }

    }

    return 0;
}
