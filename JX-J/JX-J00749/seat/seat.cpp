#include <bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i ++){
        cin >> a[i];
    }
    int k = a[1];
    sort(a + 1,a + n * m + 1,greater<int>
    int res = 1;
    for(int j = 1; j <= m; j ++){
        if(j % 2 == 1){
            for(int i = 1; i <= n; i ++){
                b[i][j] = a[res ++];
            }
        }else{
            for(int i = n; i >= 1; i --){
                b[i][j] = a[res ++];
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(b[i][j] == k){
                cout << j << ' ' << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
