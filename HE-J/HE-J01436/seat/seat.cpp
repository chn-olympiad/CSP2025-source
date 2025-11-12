#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c;
    cin >> n >> m;
    int a[105];
    int b[12][12] = { };
    for (int i = 1;i <=n*m;i++){
        cin >> a[i];
       // cout << a[i] << endl;
    }
    c = a[1];
    //cout << n << m;
    //cout << 1;
    for (int i = 1;i <= n * m;i++){
        for (int j = 1;j <= n*m;j++){
            //cout << 4;
            if (a[j+1] > a[j]){
                int f = a[j];
                a[j] = a[j + 1];
                a[j+1] = f;
               // cout << f;
            }
        }
    }
    //cout << a[1] << a[2] << a[3];
    for (int i = 1;i <= m;i++){
        if (i %2 != 0){
            for (int j = 1;j <=n;j++){
                b[j][i] = a[(i-1)*n + j];
                //cout << 2;
            }
        }
        else {
            for (int j = n;j >= 1;j--){
                b[j][i] = a[(i-1)*n + j];
                //cout << 3;
            }
        }
    }
    for (int i = 1;i <= m;i++){
        for (int j = 1;j <= n;j++){
            //cout << b[j][i] << ' ';
            if(b[j][i] == c){
               // cout <<c;
                cout << i << ' ' << j;
            }
        }
        //cout << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
