#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, ;
    cin >> n >> m;
    int a[205];
    for(int i = 1; i <= n*m; i++){
        cin a[i];
    }
    int r = a[1];

    sort(a+1, a+(n*m)+1);
    int s[15][15];
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n*m; k++){
                s[i][j] = a[k];
            }
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[i][j] == r){
                cout << i << " " << j;
            }
        }
    }



    return 0;
}

