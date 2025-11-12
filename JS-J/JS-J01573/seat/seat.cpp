#include <bits/stdc++.h>
using namespace std;

int a[110];
int b[15][15];
bool t[15][15];
int dep = 0;
int n , m;

bool cmp(int x , int y){
    return x > y;
}

void f(int x , int y){
    t[x][y] = 1;
    dep++;
    b[x][y] = a[dep];
    if(dep == n * m){
        return;
    }
    if(x + 1 <= n && t[x + 1][y] == 0){
        f(x + 1 , y);
    }else if(x - 1 >= 1 && t[x - 1][y] == 0){
        f(x - 1 , y);
    }else if(x + 1 > n && t[x][y + 1] == 0){
        f(x , y + 1);
    }else if(x - 1 < 1 && t[x][y + 1] == 0){
        f(x , y + 1);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    int temp = a[1];
    sort(a + 1 , a + n * m + 1 , cmp);
    f(1 , 1);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
          cout << b[i][j] << " ";
       }
       cout << endl;
   }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(b[i][j] == temp){
                cout << j << " " << i << endl;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
