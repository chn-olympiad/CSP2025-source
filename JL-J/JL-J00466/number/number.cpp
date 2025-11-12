#include<bits/stdc++.h>
using namespace std;
int b[1000];
int main(){
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    int c = 0;
    int x;
    cin >> x;
    while(x != 0){
        if(x % 10 >= 0 && x % 10 <= 9){
            c++;
            b[c] = x % 10;
        }
        x /= 10;
    }
    for(int i = 1; i <= c; i++){
        for(int j = 1; j < c; j++){
            int d = b[j + 1];
            int e = b [j];
            if(b[j + 1] > b[j]){
                b[j + 1] = e;
                b[j] = d;
            }
        }
    }
    for(int i = 1; i <= c; i++){
        cout << b[i];
    }
    return 0;
}
