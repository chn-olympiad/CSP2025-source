#include<bits/stdc++.h>
using namespace std;
int n , s , a[5005];
long long q = 998244353;
bool d(){
    int tmp = a[1] + a[2] + a[3];
    int x = max(max(a[1] , a[2]) , a[3]) * 2;
    if(tmp > x) return true;
    return false;
}

int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin>> n;
    bool tmp = true;
    for(int i = 1; i <= n; i++){
        cin>> a[i];
        if(a[i] > 1) tmp = false;
    }
    if(n <= 3){
        if(n == 3 && d()) cout<< 1 % q;
    }
    else{
        if(tmp){
            cout<< n * (n - 1) * (n - 2) / 6 % q;
        }
    }
    return 0;
}
