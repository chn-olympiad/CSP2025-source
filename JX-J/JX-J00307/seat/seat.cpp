#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000];
int a1[1000];
int b[101][101];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i ++){
        cin >> a[i];
    }
    int k = a[1];
    sort(a + 1, a + n*m + 1);
    for(int i = n*m;i >= 1;i --){
        a1[m*n - i + 1] = a[i];
    }
    int g = 1;
    for(int j = 1;j <= m, g <= n*m;j ++){
        if(j % 2 != 0){
            for(int i = 1;i <= n;i ++){
                if(a1[g] == k){
                    cout << j << " " << i;
                    return 0;
                }
                b[i][j] = a1[g];
                g ++;
            }
        }
        else{
            for(int i = n; i >= 1; i --){
                if(a1[g] == k){
                    cout << j << " " << i;
                    return 0;
                }
                b[i][j] = a1[g];
                g ++;
            }
        }       
    }
    return 0;
}