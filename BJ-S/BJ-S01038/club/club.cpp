#include <bits/stdc++.h>
using namespace std;
int t, n, a[10005][5], pos[10005], tong[10005];
int cnt = 1;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >>t;
    while(t--){
        cin >>n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 3; j++){
                cin >>a[i][j];
            }
        }
        int maxn = -1e9;
        if(n == 2){
            for(int i =  1; i <= 3; i++){
                for(int j = 1; j <= 3; j++){
                    if(i != j){
                        maxn = max(maxn, a[1][i] + a[2][j]);
                    }
                }
            }
            cout << maxn <<endl;
            return 0;
        }
        else {
            int ans = 0;
            for(int i = 1; i <= n; i++){
                int maxn_ = 0;
                for(int j = 1; j <= 3; j++){
                    maxn_ = max(maxn_, a[i][j]);
                }
                ans+=maxn_;
            }
            cout <<ans;
        }
    }
    return 0;
}
