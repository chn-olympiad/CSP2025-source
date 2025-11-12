//prinoty
#include <bits/stdc++.h>
#define MAXN (100010)

using namespace std;
int del[4][MAXN];
int T, N;
int cnt[4];
int A[MAXN][4];
long long ans;
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--) {
        memset(del, 0, sizeof del);
        memset(cnt, 0, sizeof cnt);
        memset(A, 0, sizeof A);
        ans = 0;
        cin >> N;
        for(int i=1;i<=N;i++) {
            int mmax = 0, maxn = 0;
            int mmid = 0, midn = 0;
            for(int j=1;j<=3;j++) {
                cin >> A[i][j];
                if(A[i][j] >= mmax) {
                    mmid = mmax;
                    midn = maxn;
                    mmax = A[i][j];
                    maxn = j;
                }else if(A[i][j] >= mmid) {
                    midn = j;
                    mmid = A[i][j];
                }
            }
            //cout << mmax << " " << mmid << endl;
            ans += mmax;
            del[maxn][++cnt[maxn]] = mmax - mmid;
        }
        int out_num = 0;
        for(int i=1;i<=3;i++) {
            //cout << cnt[i] << endl;
            if(cnt[i] > N/2) {
                sort(del[i]+1, del[i]+cnt[i]+1);
                out_num = i;
            }
        }
        if(out_num != 0)
            for(int i=1;cnt[out_num]-i>=N/2;i++) {
                ans -= del[out_num][i];
            }
        cout << ans << endl;
    }
    return 0;
}
