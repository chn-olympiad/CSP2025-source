#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a[10001] = {},b[1001][1001] = {};
    int n,m,l,k = 1;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> a[i];
    }
    l = a[1];
    sort(a+1,a+n*m+1);
    for(int i = m;i >= 1;i--){
        if(i%2 == 1){
            for(int j = n;j >= 1;j--){
                b[j][i] = a[k++];
            }
        }else{
            for(int j = 1;j <= n;j++){
                b[j][i] = a[k++];
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(b[i][j] == l){
                cout << i << " " << j;
                break;
            }
        }
    }
    return 0;
}

