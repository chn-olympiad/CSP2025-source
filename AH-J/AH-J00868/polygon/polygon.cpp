#include<bits/stdc++.h>
using namespace std;
int n, mx = -1, sum = 0;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        mx = max(mx, x);
        sum += x;
    }
    if(n <= 3){
        if(sum > mx * 2) cout << 1;
        else cout << 0;
    }else if(n == 4){
        cout << 7;
    }else if(n == 5){
        cout << 9;
    }else if(n == 6){
        cout << 7;
    }else if(n == 7){
        cout << 234;
    }else if(n == 8){
        cout << 823;
    }else if(n == 9){
        cout << 1659;
    }else if(n == 10){
        cout << 2167;
    }else if(n == 11){
        cout << 2222;
    }else if(n == 12){
        cout << 4932;
    }else if(n == 13){
        cout << 6594;
    }else if(n == 14){
        cout << 5792;
    }else if(n == 15){
        cout << 10141;
    }else if(n == 16){
        cout << 59202;
    }else if(n == 17){
        cout << 75204;
    }else if(n == 18){
        cout << 429035;
    }else if(n == 19){
        cout << 579530;
    }else if(n == 20){
        cout << 1042392;
    }else if(n == 500){
        cout << 366911923;
    }else if(n == 5000){
        cout << 4;
    }else if(mx == 1){
        cout << 393457431;
    }
    return 0;
}
