#include "bits/stdc++.h"
using namespace std;
/*
const int N = 100000;

int t;
int a[N + 10][4];
int p[N + 10][4];
*/
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
/*    cin >> t;

    for(int i = 1;i <= t;i++){
        memset(p,0,sizeof(p));
        int n,m,ps;
        int cnt = 0;

        cin >> n;
        m = n / 2;

        for(int j = 1;j <= n;j++){
            int mx = INT_MIN;
            for(int k = 1;k <= 3;k++){
                cin >> a[k][j];
                if(a[k][j] >= mx){
                    mx = a[k][j];
                    ps = k;
                }
            }
            if(p[ps][j] <= m){
                p[ps][j]++;
                cnt += a[ps][j];
            }
        }
        cout << cnt << endl;
    }
*/
    return 0;
}
