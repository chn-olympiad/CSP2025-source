#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct Dat {
    int stu;
    int club;
    int val;
    bool operator< (const Dat& other) const {
        return other.val < val;
    }
};

int N,M;
Dat arr[MAXN * 3];
bool vis[MAXN];
int cnt[5];

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    for(int i=1; i<=T; i++) {
        memset(arr,0,sizeof(arr));
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        cin >> N;
        M = N * 3;
        for(int i=1; i<=N; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            arr[(i - 1) * 3 + 1].club = 1;
            arr[(i - 1) * 3 + 1].stu = i;
            arr[(i - 1) * 3 + 1].val = a;

            arr[(i - 1) * 3 + 2].club = 2;
            arr[(i - 1) * 3 + 2].stu = i;
            arr[(i - 1) * 3 + 2].val = b;

            arr[(i - 1) * 3 + 3].club = 3;
            arr[(i - 1) * 3 + 3].stu = i;
            arr[(i - 1) * 3 + 3].val = c;
        }
        sort(arr+1,arr+1+M);
        int ans = 0;
        int stu_cnt = 0;
        for(int i=1; i<=M; i++) {
            if (vis[arr[i].stu]) continue;
            if (cnt[arr[i].club] == N / 2) continue;
            ans += arr[i].val;
            stu_cnt++;
            vis[arr[i].stu] = 1;
            cnt[arr[i].club]++;
            if (stu_cnt == N) break;
        }
        cout << ans << "\n";
    }
    return 0;
}