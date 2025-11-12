#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 7;
int n,t,a[N][4],cnt[4],f[N],d[N],ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for (int tim = 1;tim <= t;tim++){
        cin >> n;
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= 3;j++){
                cin >> a[i][j];
            }
            if (a[i][1] > a[i][2]){
                if (a[i][2] > a[i][3]){
                    cnt[1] ++;
                    f[i] = 1;
                    ans += a[i][1];
                }
                else if (a[i][3] > a[i][1]){
                    cnt[3]++;
                    f[i] = 3;
                    ans += a[i][3];
                }
                else{
                    cnt[1] ++;
                    f[i] = 1;
                    ans += a[i][1];
                }
            }
            else{
                if (a[i][2] > a[i][3]){
                    cnt[2] ++;
                    f[i] = 2;
                    ans += a[i][2];
                }
                else{
                    cnt[3]++;
                    f[i] = 3;
                    ans += a[i][3];
                }
            }
            //cout << f[i] << " ";
        }
       // cout << cnt[1] << " " << cnt[2] << " " << cnt[3] <<endl;
        int k = 0;
        if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
            cout << ans <<endl;
          //  cout << "hjjh" << endl;
            return 0;
        }
        if (cnt[1] > n / 2){
               // cout << "hjjh" <<endl;
            for (int i = 1;i <= n;i++){
                k++;
                if (f[i] == 1) {
                    d[k] = min(a[i][1] - a[i][2],a[i][1] - a[i][3]);
                    //cout << d[k] << " ";
                }
            }
            sort(d + 1,d + k + 1);
            int cur = 0;
            for (int i = cnt[1];i > cnt[1] - n / 2;i--){
                cur++;
                ans -= d[cur];
            }
        }
        if (cnt[2] > n / 2){
            for (int i = 1;i <= n;i++){
                k++;
                if (f[i] == 2) d[k] = min(a[i][2] - a[i][1],a[i][2] - a[i][3]);
            }
            sort(d + 1,d + k + 1);
            int cur = 0;
            for (int i = cnt[2];i > cnt[2] - n / 2;i--){
                cur++;
                ans -= d[cur];
            }
        }
         if (cnt[3] > n / 2){
            for (int i = 1;i <= n;i++){
                k++;
                if (f[i] == 3) d[k] = min(a[i][3] - a[i][1],a[i][3] - a[i][2]);
            }
            sort(d + 1,d + k + 1);
            int cur = 0;
            for (int i = cnt[3];i > cnt[3] - n / 2;i--){
                cur++;
                ans -= d[cur];
            }
        }
        cout << ans << endl;
        memset(a,0,sizeof a);
        cnt[0] = 0;
        cnt[1] = 0;
        cnt[2] = 0;
        cnt[3] = 0;
        memset(f,0,sizeof f);
        memset(d,0,sizeof d);
        ans = 0;

    }
    return 0;
}
