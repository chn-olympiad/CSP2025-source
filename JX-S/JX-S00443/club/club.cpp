#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","r",stdout);
    int t;
    cin >> t;
    int a[1005];
    int d[t];
    int n;
    for (int i = 1;i <= t;i++){
        int h = 0;
        for (int j = 0;j <= 1004;j++){
            a[j] = 0;
        }
        cin >> n;
        for (int j = 1;j <= n * 3;j++){
            cin >> a[j];
        }
        for (int j = 1;j <= n * 3;j++){
            if (j % 3 == 1){
                if (a[j] > a[j + 1] && a[j] > a[j + 2]){
                    h += a[j];
                }
                if (a[j] < a[j + 1] && a[j + 1] > a[j + 2]){
                    h += a[j + 1];
                }
                if (a[j] < a[j + 2] && a[j + 1] < a[j + 2]){
                    h += a[j + 2];
                }
                if (a[j] == a[j + 2] && a[j + 1] == a[j + 2]){
                    h += a[j];
                }
            }
        }
        d[i] = h;
    }
    for (int i = 1;i <= t;i++){
        cout << d[i] << " ";
    }
    return 0;
}
