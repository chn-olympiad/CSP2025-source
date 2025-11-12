#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    int a[105] = {0};
    for (int i=1; i<=n*m; i++){
        cin >> a[i];
    }
    int sum = a[1];
    sort(a, a+n*m+1);
    int b[n][m] ={0};
    int i=1,j=1;//lie hang
    int flag = 1;
    int cnt = 0;
    int s = n*m;
    while (true){
        b[i][j] = a[s];
        cnt ++;
        s--;
        if ((i==n || i==1)&& cnt%n==0){
            j++;
            flag ++;
            if (i==n){
                i++;
            }else{
                i--;
            }
        }
        if (flag%2 == 1){
            i++;
        }else{
            i--;
        }
        if (cnt == n*m){
            break;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (b[i][j] == sum){
                cout << j << " " << i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
