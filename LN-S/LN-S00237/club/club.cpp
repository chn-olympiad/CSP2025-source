# include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, a[N][5], cnt[5], ans, aa[N];
vector <int> club[5];
bool cmp(int x, int y){
    return max(max(a[x][1], a[x][2]), a[x][3]) - aa[x] < max(max(a[y][1], a[y][2]), a[y][3]) - aa[y];
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", & t);
    while (t --){
        for (int i = 1; i <= 3; i ++) club[i].clear();
        for (int i = 1; i <= 3; i ++) cnt[i] = 0;
        ans = 0;
        scanf("%d", & n);
        for (int i = 1; i <= n; i ++){
            scanf("%d%d%d", & a[i][1], & a[i][2], & a[i][3]);
            int k;
            if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) k = 1;
            else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) k = 2;
            else k = 3;
            club[k].push_back(i);
            cnt[k] ++;
            ans += a[i][k];
            int xx = a[i][k];
            aa[i] = (xx == a[i][1] ? max(a[i][2], a[i][3]) : (xx == a[i][2] ? max(a[i][1], a[i][3]) : max(a[i][1], a[i][2])));
        }
        int tmp = -1;
        for (int i = 1; i <= 3; i ++) if (cnt[i] > (n / 2)) tmp = i;
        if (tmp == -1){
            printf("%d\n", ans);
            continue;
        }
        sort(club[tmp].begin(), club[tmp].end(), cmp);
        for (int i = 0; i < cnt[tmp] - (n / 2); i ++){
            int now = club[tmp][i];
            ans -= (max(max(a[now][1], a[now][2]), a[now][3]) - aa[now]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
