#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][5];
int cnt[5];
int b[N];
int tmp[N][5];
int check(int n){
    for(int i = 1;i <= 3;i++){
        if(cnt[i] > n / 2){
            return i;
        }
    }
    return 0;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int maxxsum = 0;
        for(int  i = 1;i <= 3;i++){
            cnt[i] = 0;
        }
        for(int i = 1;i <= n;i++){
            int maxx = 0;
            for(int j = 1;j <= 3;j++){
                cin >> a[i][j];
                if(maxx <= a[i][j]){
                    maxx = a[i][j];
                    b[i] = j;
                }
            }
            maxxsum += maxx;
            cnt[b[i]]++;
        }
        //cout << maxxsum << " ";
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++){
                tmp[i][j] = a[i][b[i]] - a[i][j];
                //cout << tmp[i][j] << " ";
            }
            //cout << "\n";
        }
        //cout << check(n) << "\n";
        //for(int  i = 1;i <= 3;i++){
            //cout << cnt[i] << " ";
        //}
        //cout << "\n";
        while(check(n) != 0){
            int x = check(n);
            //cout << check(n) << " ";
            int minn = 1e9;
            int flag = 0, num = 0;
            for(int i = 1;i <= n;i++){
                if(b[i] == x){
                    for(int j = 1;j <= 3;j++){
                        if(j != b[i]){
                            if(minn > tmp[i][j]){
                                minn = tmp[i][j];
                                flag = j;
                                num = i;
                            }
                        }
                    }
                }

            }
            b[num] = flag;
            //cout << flag << " " << minn << "\n";
            maxxsum -= minn;
            cnt[flag]++;
            cnt[x]--;
        }
        cout << maxxsum << "\n";
    }
    return 0;
}
