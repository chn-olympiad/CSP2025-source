#include<bits/stdc++.h>
using namespace std;
int a[100];
void nsort(int s){
    for(int i = 1; i < s; i++){
        for(int j = i + 1; j <= s; j++){
            if(a[i] < a[j]) swap(a[i] , a[j]);
        }
    }
}
int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n , m;
    cin>> n >> m;
    if(n == 1 && m == 1){
        int x;
        cin>> x;
        cout<< 1 << " " << 1;
    }
    else{
        bool q = true;
        for(int i = 1; i <= n * m; i++){
            cin>> a[i];
            if(a[i - 1] - a[i] != 1) q = false;
        }
        if(a[1] == 1) cout<< n << " " << m;
        else if(q) cout<< 1 << " " << 1;
        else{
            int x = a[1];
            nsort(n * m);
            for(int i = 1; i <= 100; i++){
                if(a[i] == x){
                    x = i;
                    break;
                }
            }
            int tmp = ceil(1.0 * x / n);
            if(tmp % 2 == 1){
                int y = x - (tmp - 1) * n;
                cout<< tmp << " " << y;
            }
            if(tmp % 2 == 0){
                int y = n - (x - (tmp - 1) * n) + 1;
                cout << tmp << " " << y;
            }
        }
    }
    return 0;
}
