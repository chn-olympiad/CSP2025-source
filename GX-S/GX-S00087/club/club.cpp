#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int t, n, nn;

int g_sortBy;
struct Student {
    int a[3];
    struct llll {
        int a, id;
        bool operator<(const llll& another) {
            return a > another.a; // down
        }
    } fav[3];
    int loss;
    bool operator<(const Student& another) {
        if (g_sortBy == -1) {
            return loss < another.loss;
        }
        return a[g_sortBy] > another.a[g_sortBy]; // down
    }
} stu[MAXN+1];
Student mlist[3][MAXN+1];
int cnt[3];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    long long ans;
    cin >> t;
    int overflow, favId;
    while (t--) {
        cin >> n;
        nn = n>>1, ans = 0;
        cnt[0]=cnt[1]=cnt[2]=0;
        for (int i = 1; i <= n; i++) {
            cin >> stu[i].a[0] >> stu[i].a[1] >> stu[i].a[2];
            stu[i].fav[0].a=stu[i].a[0], stu[i].fav[0].id=0;
            stu[i].fav[1].a=stu[i].a[1], stu[i].fav[1].id=1;
            stu[i].fav[2].a=stu[i].a[2], stu[i].fav[2].id=2;
            sort(stu[i].fav, stu[i].fav+3);
            favId=stu[i].fav[0].id;
            stu[i].loss=stu[i].fav[0].a-stu[i].fav[1].a;
            cnt[favId]++, ans+=stu[i].fav[0].a;
            mlist[favId][cnt[favId]] = stu[i];
        }
        if (cnt[0]<=nn && cnt[1]<=nn && cnt[2]<=nn) {
            cout << ans << '\n';
            continue;
        }
        if (cnt[0]>nn)overflow=0;
        else if (cnt[1]>nn)overflow=1;
        else overflow=2;
        g_sortBy = -1;
        sort(mlist[overflow]+1, mlist[overflow]+1+cnt[overflow]);
        for (int i = 1; i <= cnt[overflow] - nn; i++) {
            ans -= mlist[overflow][i].loss;
        }
        cout << ans << '\n';
    }
    return 0;
}