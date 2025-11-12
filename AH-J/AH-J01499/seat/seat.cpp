#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[110];
    int b[10][10];
    int mset = 1;
    int ass ;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> a[i];
    }
    int me = a[1];
    for(int i = 1;i <= n*m;i++){
        for(int j = i;j > 0;j--){
            if(a[j] >= a[j-1]){
                ass = a[j];
                a[j] = a[j-1];
                a[j-1] = ass;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            b[i][j] = a[mset];
            mset++;
            if(b[i][j] == me){
                cout << i << " "<< j;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}


