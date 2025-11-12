#include<bits/stdc++.h>
using namespace std;
/*<====================>*/
const int N = 15*15;
int m, n, a[N], b, k;
/*<====================>*/
bool mycmp(int a, int b){return a > b;}
/*<====================>*/
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++)
        cin >> a[i];
    b = a[1];
    sort(a + 1, a + 1 + m * n, mycmp);
    for(int i = 1; i <= m; i++){//列
        if(i % 2 == 1){
            for(int j = 1; j <= n; j++){//行（正）
                k++;
                if(a[k] == b){
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
        if(i % 2 == 0){
            for(int j = n; j >= 1; j--){//行（倒）
                k++;
                if(a[k] == b){
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
