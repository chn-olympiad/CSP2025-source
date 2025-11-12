#include <bits/stdc++.h>
using namespace std;
int x[20][20];
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[1000];
    int n,m;
    int num,xi = 1;
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    num = a[1];
    sort(a+1,a+n*m+1,cmp);
    for (int i = 1;i <= m;i++){
        if (i % 2 == 1){
            for (int j = 1;j <= n;j++){
                x[i][j] = a[xi];
                xi++;
                if (x[i][j] == num){
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }else {
            for (int j = n;j >= 1;j--){
                x[i][j] = a[xi];
                xi++;
                if (x[i][j] == num){
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
