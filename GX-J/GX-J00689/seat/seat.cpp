#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> temp(n*m);
    int a[15][15] = {0};
    int r = 0;
    for (int i=1; i<=n*m; i++){
        cin >>  temp[i];
        if (i == 1){
            r = temp[i];
        }
    }
    for (int i=1; i<n*m; i++){
       for (int j=1; j<n*m; j++){
            if (temp[i] > temp[j]){
                swap(temp[i], temp[j]);
            }
       }
    }

    for (int i=1; i<=n; i++){
       for (int j=1; j<m; j++){
            a[i][j] = temp[i*j];
       }
    }
    for (int i=1; i<=n; i++){
       for (int j=1; j<m; j++){
            if (a[i][j] == r){
                cout << j << " " << i << endl;
                return 0;
            }
       }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
