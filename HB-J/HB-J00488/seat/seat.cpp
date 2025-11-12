#include<bits/stdc++.h>
using namespace std;
int ton[110],ton2[110][110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout); 
    int m,n,xr;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <=m;j++){
            int tmp;
            cin >> tmp;
            ton2[i][j] = tmp;
            ton[tmp] = 1;
        }
    }
    xr = ton2[1][1];
    int pm = 0;
    for(int i = 100;i >= xr;i--){
        if(ton[i] == 1){
            pm++;
        }
    }
    int ji = 0;
    for(int i = 1;i <= m;i++){
        if(i % 2 == 1){
            for(int j = 1;j <= n;j++){
               ji++;
               if(ji == pm){
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }else{
            for(int j = n;j >= 1;j--){
               ji++;
               if(ji == pm){
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}