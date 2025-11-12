#include<bits/stdc++.h>
using namespace std;

long long n , a[1000001] , f = 0 , cnt = 0;
void bf(int k , int dis , int sum){
    for(int i = dis ; i <= n - k + 1 ; i ++){
        if(k == dis)
            if(sum <= a[i]) return;
            else cnt ++;
        bf(k , dis + 1 , sum + a[i]);
    }
}
int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        if(a[i] != 1){
            f = 1;
        }
    }
    sort(a + 1 , a + n + 1);
    if(n < 3){
        cout << 0;
        return 0;
    }else if(!f){
        cout << n - 2;
        return 0;
    }if(n == 3){
        if(a[3] >= a[1] + a[2]){
            cout << 0;
            return 0;
        }
        cout << 1;
        return 0;
    }
    for(int i = 3 ; i <= n ; i ++){
        bf(i , 1 , 0);
    }
    cout << cnt;
    return 0;
}
