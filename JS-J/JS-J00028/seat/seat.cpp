#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[105];
int xx = 0;
int pos = 0;
void sol(){
    int x = 1 , y = 1 , cnt = 0;
    while(1){
        cnt++;
        if(cnt == pos){
            cout << y << " " << x << endl;
            return;
        }
        if(y % 2 == 1){
            x++;
        }else{
            x--;
        }
        if(x == 0){
            x = 1;
            y++;
        }else if(x == n + 1){
            x = n;
            y++;
        }
    }
}
int main() {
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n * m ; i++){
        cin >> a[i];
    }
    xx = a[1];
    sort(a + 1 , a + n * m + 1 , greater<int>());
    for(int i = 1 ; i <= n * m ; i++){
        if(a[i] == xx){
            pos = i;
            break;
        }
    }
    sol();
    return 0;
}
