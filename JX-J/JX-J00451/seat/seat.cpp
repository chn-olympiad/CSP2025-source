#include <iostream>
using namespace std;
int main(){
    freopen("seat.in",r,"stdin");
    freout("seat.out",w,"stdout");
    int n,m;
    cin >> n >> m;
    int a[100][100];
    for (int i = 0;i<=m-1;i++){
        for (int j = 0;j<=n-1;j++){
            cin >> a[i][j];
        }
    }
    int l = a[0][0];
    for (int y = 0;y<=n-1;y++){
        for (int q = 0;q<=m-1;q++){
            for (int w = 0;w<=n-1;w++){
                if (a[q][w]<a[q][w-1]&&q%2 == 1){
                    int u = a[q][w];
                    a[q][w] = a[q][w-1];
                    a[q][w-1] = u;
                }
                else if (a[q][w]>a[q][w-1]&&q%2 == 0){
                    int g = a[q][w];
                    a[q][w] = a[q][w-1];
                    a[q][w-1] = g;
                }
                else if (a[q][n]<a[q+1][n]&&q%2 == 1){
                    int x = a[q][n];
                    a[q][n] = a[q+1][n];
                    a[q+1][n] = x;
                }
            }
        }
    }
    for (int o = 0;o<=m-1;o++){
        for (int p = 0;p<n-1;p++){
            if (a[o][p] == l){
                cout << o << " " << p;
                break;
            }
        }
    }
    return 0;
}
