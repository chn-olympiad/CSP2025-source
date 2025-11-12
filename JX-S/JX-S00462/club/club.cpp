#include <bits/stdc++.h>
using namespace std;
int t, n, a[100001][4], maxn[100001][4], d[100001];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
    cin >> t;
    for(int i = 1; i <= t; i ++){
        cin >> n;
        int sum = n / 2;
        int ans = 0;
        int spe = 0;
        int count = 0;
        int cnt[100001] = {0};
        for(int j = 1; j <= n; j ++){
           cin >> a[j][1] >> a[j][2] >> a[j][3];
           if(a[j][1] >= a[j][2] && a[j][1] >= a[j][3]){
                maxn[j][1] = 1;
                if(a[j][2] >= a[j][3]){
                    maxn[j][2] = 2;
                    maxn[j][3] = 3;
                }else{
                    maxn[j][3] = 2;
                    maxn[j][2] = 3;
                }
            }else if(a[j][1] <= a[j][2] && a[j][2] >= a[j][3]){
                maxn[j][1] = 2;
                if(a[j][1] >= a[j][3]){
                    maxn[j][2] = 1;
                    maxn[j][3] = 3;
                }else{
                    maxn[j][3] = 1;
                    maxn[j][2] = 3;
                }

            }else{
                maxn[j][1] = 3;
                if(a[j][1] >= a[j][2]){
                    maxn[j][2] = 1;
                    maxn[j][3] = 2;
                }else{
                    maxn[j][3] = 1;
                    maxn[j][2] = 2;
                }
            }
        }
        for(int j = 1; j <= n; j ++){
            if(cnt[maxn[j][1]] < sum){
                cnt[maxn[j][1]] ++;
            }else{
                cnt[maxn[j][2]] ++;
                count = 1;
                spe = maxn[j][1];
            }
        }
        if(count == 0){
            for(int j = 1; j <= n; j ++){
                ans += a[j][maxn[j][1]];
            }
        }else{
            for(int j = 1; j <= n; j ++){
                if(maxn[j][1] != spe) ans += a[j][maxn[j][1]];
                else{
                   ans += a[j][maxn[j][2]];
                   d[j] = a[j][maxn[j][1]] - a[j][maxn[j][2]];
                }
            }
            sort(d + 1,d + n);
            for(int j = n; j >= sum + 1; j --){
                ans += d[j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
