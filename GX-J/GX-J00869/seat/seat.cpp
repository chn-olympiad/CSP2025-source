#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin>>a[i];
    }
    int u = a[1], v;
    sort(a, a+n*m+1);
    for(int i = m*n;i >= 1;i--){
        if(a[i] == u){
            v = m*n-i+1;
            break;
        }
    }
    for(int i = 1;i <= m;i++){
        if(i%2 == 1){
            for(int j = 1;j <= n;j++){
                v--;
                if(v == 0){
                    cout << i << " " << j;
                    return 0;
                }
            }
        }else{
            for(int j = n;j >= 1;j--){
                v--;
                if(v == 0){
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}


