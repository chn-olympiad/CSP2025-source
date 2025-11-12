#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[110],c,r;
bool flag;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++){
        cin >> b[i];
    }
    int xiaoR = b[1];
    sort(b + 1,b + (n * m) + 1,cmp);
    for (int i = 1;i <= m;i++){
        int o = 1;
        if (flag == 0){
            for (int j = 1;j <= n;j++){
                if (i > j){
                    a[i][j] = b[i * j];
                }else if (i == j){
                    a[i][j] = b[i * j];
                }
                else{
                    a[i][j] = b[i + j];
                }
                flag = 1;
            }
        }else{
            for (int j = n;j >= 1;j--){
                if (i > j){
                    a[i][j] = b[i * j];
                }else if (i == j){
                    a[i][j] = b[i * j];
                }
                else{
                    a[i][j] = b[i + j];
                }
                flag = 0;
            }
        }
    }
    for (int i = 1;i <= m;i++){
        for (int j = 1;j <= n;j++){
            if (a[i][j] == xiaoR){
                c = j;
                r = i;
            }
        }
    }
    cout << c << " " << r;
    return 0;
}
