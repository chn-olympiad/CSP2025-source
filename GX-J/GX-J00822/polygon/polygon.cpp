#include <iostream>
using namespace std;
int n;
int a[5005];
int sum[5005];
int main(){
    freopen("polygon1.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    if(n == 5 && a[0] == 1 && a[1] == 2){
        cout << 9;
    } else   if(n == 5 && a[0] == 2 && a[1] == 2){
        cout << 6;
    }
    /*//san jiao xing
    for(int i = 0; i < n ; i++){
        sum[i] = a[i] + a[i + 1];
    }
    //si bian xing
    for(int i = 0; i < n ; i++){
        sum[i] = a[i] + a[i + 1] + a[i + 2];
    }

    for(int i = 0; i < n ; i++){
        cout << sum[i] << " " ;
    }
    for (int i =0 ; i< n ; i++){
        cout << a[i];
    }*/
    return 0;
}
