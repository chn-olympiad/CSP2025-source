#include <bits/stdc++.h>
using namespace std;

int n, m, kss[255];

bool cmp(int a, int b){return a > b;}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++){
        cin >> kss[i];
    }
    int xiaor = kss[1];
    sort(kss + 1, kss + n * m + 1, cmp);
    int xh = 0, hang;
    for (int lie = 1; lie <= m; lie++){
        for (int j = 1; j <= n; j++){
            xh++;
            if (kss[xh] == xiaor){
                if (lie % 2 == 0){
                    hang = n - j + 1;
                }else{
                    hang = j;
                }
                cout << lie << ' ' << hang;
                return 0;
            }
        }
    }
    return 0;
}
