#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105], tmp;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
    }tmp = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int x = 1;
    int y = 1;
    int flag = 0;
    for(int i = 1;i <= n * m;i++){
        if(a[i] == tmp)break;
        if(flag == 0)x++;
        else x--;
        if(x > n || x < 1){
            y++;
            flag = (flag + 1) % 2;
            if(x > n)x--;
            else x++;
        }
    }
    cout << y << " " << x;
    return 0;
}
