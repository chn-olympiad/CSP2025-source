#include<bits/stdc++.h>
using namespace std;
int cmp(int A,int B){
return A > B;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m;
    cin >> n >> m;
    int a[110] = {};
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    int x = a[1];
    sort(a + 1,a+n*m + 1, cmp);
    bool f = 0;
    for(int i = 1; i <= n; i++){
         if(!f){
            for(int j = 1; j <= m; j++){
                if(a[(i - 1) * n + j] == x){
                    cout << i << ' ' << j;
                    return 0;
                }
            }
         }
         if(f){
            for(int j = m; j >= 1; j--){
                if(a[(i - 1) * n + j] == x){
                    cout << i << ' ' << m  - j + 1;
                    return 0;
                }
            }
         }
         f = !f;
    }
return 0;
}
