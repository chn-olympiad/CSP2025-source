#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[105],maps[15][15];

/*int seats(int x,int y){
    if (x == 1 && y == 1) return 1;
    if (x == 1){
        if (y % 2 == 0) return seats(x+1,y)+1;
        else return seats(x,y-1)+1;
    }
    else if (x == n){
        if (y & 2 == 0) return seats(x,y-1)+1;
        else return seats(x-1,y)+1;
    }
    else{
        if (y % 2 == 0) return seats(x+1,y)+1;
        else return seats(x-1,y)+1;
    }
}*/

bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n*m;i++)
        cin >> a[i];
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            if (i == 1 && j == 1) maps[i][j] = 1;
            else if (i == 1){
                //cout << (j & 2) << " " << j << endl;
                if (j == 2) maps[i][j] = j * n;
                else maps[i][j] = maps[i][j-2]+2*n;
            }
            else if (i == n){
                if (j == 1) maps[i][j] = i;
                else if (j == 2) maps[i][j] = i+1;
                else maps[i][j] = maps[i][j-2]+2*n;
            }
            else{
                if (j == 1) maps[i][j] = i;
                else if (j == 2) maps[i][j] = maps[i][j-1] + 2*n+1-2*i;
                else maps[i][j] = maps[i][j-2] + 2*n;
            }
        }
    }
    int k = a[1],pos;
    sort(a+1,a+n*m+1,cmp);
    for (int i = 1;i <= n*m;i++){
        if (a[i] == k){
            pos = i;
            break;
        }
    }
    /*for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            cout << maps[i][j] << " ";
        }
        cout << endl;
    }*/
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            if (maps[i][j] == pos){
                cout << j << " " << i;
                return 0;
            }
        }
    }

    return 0;
}
