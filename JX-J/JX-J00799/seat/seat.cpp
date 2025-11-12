#include<bits/stdc++.h>
using namespace std;
int n, m, s[1005], S, f;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i ++){
        cin >> s[i];
    }
    S = s[1];
    sort(s + 1, s + 1 + n * m);
    for (int i = n * m; i >= 1; i --){
        if (s[i] > S){
            f ++;
        }
        else break;
    }
    for (int i = 1; i <= m; i ++){
        if (i % 2 == 1){
            for (int j = 1; j <= n; j ++){
                f --;
                if (f == -1){
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
        else {
            for (int j = n; j >= 1; j --){
                f --;
                if (f == -1){
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
