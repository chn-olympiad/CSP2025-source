#include<bits/stdc++.h>
using namespace std;
vector<int> a;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, tmp, x = 1, y = 1, R, num = -1;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &tmp);
            a.push_back(tmp);
        }
    }
    R = a[0];
    sort(a.begin(), a.end(), cmp);
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(a[++num] == R){
                printf("%d %d", y, x);
                return 0;
            }
            if(y % 2 == 1) x++;
            else x--;
            if(x > n){
                x = n;
                y++;
            }
            if(x < 1){
                x = 1;
                y++;
            }
        }
    }
}
