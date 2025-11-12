#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5 + 5;
int T, n, sum;
int a[N][4], ans[N], cnt[4], tmp[N];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while (T--){
        memset(ans, 0, sizeof(ans));
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= 3; j++){
                cin >> a[i][j];
            }
            ans[i] = 1;
            for (int j = 2; j <= 3; j++){
                if (a[i][j] > a[i][ans[i]]){
                    ans[i] = j;
                }
            }
            sum += a[i][ans[i]];
            cnt[ans[i]]++;
        }
        int flag = 0;
        for (int j = 1; j <= 3; j++){
            if (cnt[j] > n / 2){
                flag = j;
                break;
            }
        }
        if (flag > 0){
            int cur = 0;
            for (int i = 1; i <= n; i++){
                if (ans[i] == flag){
                    int minn = 2e9;
                    for (int j = 1; j <= 3; j++){
                        if (j == flag){
                            continue;
                        }
                        minn = min(minn, a[i][ans[i]] - a[i][j]);
                    }
                    tmp[++cur] = minn;
                }
            }
            sort(tmp + 1, tmp + cur + 1);
            for (int i = 1; i <= cnt[flag] - n / 2; i++){
                sum -= tmp[i];
            }
        }
        cout << sum << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}