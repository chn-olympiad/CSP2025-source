#include<bits/stdc++.h>
using namespace std;

int n;
int a[6000];
long long ans;

int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }

    if(n == 3){
        sort(a + 1 , a + 1 + n);
        if(a[1] + a[2] + a[3] > a[3] * 2){
            cout << a[3];
        }
    }
    return 0;
}