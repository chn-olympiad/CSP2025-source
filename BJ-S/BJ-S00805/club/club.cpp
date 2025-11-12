#include<bits.stdc++.h>

using namespace std;

const int N = 100005;
int t, n, a[N][5];
int main(){
    cin >> t;
    while (t--){
        cin >> n;
        int s = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            s += max(a[i][1], max(a[i][2], a[i][3]));
        }
        if (n == 2){
            int cnt = 0;
            for (int i = 1; i <= 3; i++){
                for (int j = 1; j <= 3; j++){
                    if (i != j && a[1][i]+a[2][j] > cnt)
                        cnt = a[1][i]+a[2][j];
                }
            }
            cout << cnt << endl;
        }
        else{
            cout << s << endl;
        }
    }
    return 0;
}