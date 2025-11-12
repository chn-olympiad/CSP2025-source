#include<bits/stdc++.h>
using namespace std;
int a[100];
int e[100][100];
int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    int n, m;
    int x;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    x = a[1];
    for(int i= 1; i <= n*m; i++){
        for(int j = 1; j < n * m; j++){
            int b = a[j + 1];
            int c = a[j];
            if(a[j + 1] > a[j]){
                a[j + 1] = c;
                a[j] = b;
            }
        }
    }
    int d = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(j % 2 == 0){
                for(int z = n; z >= 1; z--){
                    e[i][z] == a[d];
                    if(a[d] == x){
                        cout << i << " " << z + 1;
                        return 0;
                    }
                    d++;
                }
                e[i][j] == a[d];
                if(a[d] == x){
                    cout << i + 1<< " " << j;
                    return 0;
                }
                d++;
            }
        }
    }
    return 0;
}
