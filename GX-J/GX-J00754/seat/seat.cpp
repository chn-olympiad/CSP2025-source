#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, h, max = -1, hs = 0, sh = 0;
    cin >> n >> m;
    h = n * m;
    int a[225];
    long long s[15][15];
    for(long long i=0; i<h; i++){
        cin >> a[i];
    }
    while(a[0] != -1){
        max = 0;
        for(int i=1; i<h; i++){
            if(a[i] > a[max]){
                max = i;
            }
        }
        a[max] = -1;
        hs ++;
    }
    for(int j=0; j<m; j++){
        if((j+1) % 2 == 0){
            for(int i=n-1; i>=0; i--){
                s[i][j] = sh;
                sh += 1;
                if(sh == hs){
                    cout << j+1 << " " << i+1;
                    break;
                    break;
                }
            }
        }else{
            for(int i=0; i<n; i++){
                s[i][j] = sh;
                sh += 1;
                if(sh == hs){
                    cout << j+1 << " " << i+1;
                    break;
                    break;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
