#include<bits/stdc++.h>
using namespace std;
int n, m, ren, ji, y = 1;
int a[100010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    ren = n * m;
    for(int i = 1;i <= ren;i++){
        cin >> a[i];
    }
    ji = a[1];
    sort(a, a+ren+1);
    y = ren;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[y] == ji){
                cout << i << " " << j;
                return 0;
            }
            y--;
        }
        i++;
        for(int j = m;j >= 1;j--){
            if(a[y] == ji){
                cout << i << " " << j;
                return 0;
            }
            y--;
        }
    }
    return 0;
}
