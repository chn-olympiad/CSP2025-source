#include<bits/stdc++.h>
using namespace std;
int t, n;
const int maxn = 1e5 + 10;
int a[maxn][4];
long long vis[4];
long long ans = 0;
struct line {
    int vala, valb;
}b[maxn], c[maxn];
bool cmpa(line u, line v) {
    return u.vala > v.vala;
}
bool cmpb(line u, line v) {
    return u.valb > v.valb;
}
void find(int lst, long long sum, int cnt, int n) {
    if(cnt == n) {
        ans = max(ans, sum);
        return ;
    }
    for(int i = lst + 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            if(vis[j] >= n / 2)
                continue;
            vis[j]++;
            find(i, sum + a[i][j], cnt + 1, n);
            vis[j]--;
        }
    }
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        bool flaga = false, flagb = false;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                cin >> a[i][j];
                if(j == 2 && a[i][j] != 0)
                    flaga = true;
                if(j == 3 && a[i][j] != 0)
                    flagb = true;
            }
        }
        ans = 0;
        if(n <= 30) {
            find(0, 0, 0, n);
            cout << ans << "\n";
            continue;
        }
        if(!flaga) {
            int c[maxn];
            for(int i = 1; i <= n; i++)
                c[i] = a[i][1];
            sort(c + 1, c + 1 + n);
            for(int i = 1; i <= n / 2; i++)
                ans += c[i];
            cout << ans << "\n";
        }
        if(!flagb) {
            for(int i = 1; i <= n; i++) {
                b[i].vala = c[i].vala = a[i][1];
                b[i].valb = c[i].valb = a[i][2];
            }
            sort(b + 1, b + 1 + n, cmpa);
            sort(c + 1, c + 1 + n, cmpb);
            long long ansb = 0, ansc = 0;
            for(int i = 1; i <= n / 2; i++) {
                ansb += b[i].vala;
                ansc += c[i].valb;
            }
            for(int i = n / 2 + 1; i <= n; i++) {
                ansb += b[i].valb;
                ansc += c[i].vala;
            }
            cout << max(ansb, ansc) << "\n";
        }
    }
    return 0;
}
