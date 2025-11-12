#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int s[101];
    int hc;
    int R;
    for (int i = 0;i < n * m;i++){
        cin >> s[i];
    }
    R = s[0];
    int c = 1,r = 1;
    for (int i = 1;i < n * m;i++){
        for (int j = 0;j < n * m;j++){
            hc = min(s[j],s[j-1]);
            s[j-1] = max(s[j],s[j-1]);
            s[j] = hc;
        }
    }
    int l = 0;
    for (int i = 0;i < n*m;i++){
        if (s[i] == R){
            if (i % n == 0 && i % m != 0){
                cout << i / m + c << " " << i % n + r+1;
                return 0;
            }
            if (i % m == 0 && i % n != 0){
                cout << i / m + c << " " << i % n + r-1;
                return 0;
            }
            cout << i / m + c << " " << i % n + r;
            return 0;
        }
    }
}
