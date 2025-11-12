#include<bits/stdc++.h>
using namespace std;
int xc[15][10010];
bool che[10010][10010], che2[10010][10010];

struct dl{
    int le, ri;//the two cities it connects
    int cd;//lenghth
} b[1000010];

bool cmp(dl d, dl l){
    return d.cd < l.cd;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    memset(che2, false, sizeof(che2));
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &b[i].le, &b[i].ri, &b[i].cd);
        che2[b[i].le][b[i].ri] = che2[b[i].ri][b[i].le] = true;
    }
    for (int i = 1; i <= k; i++){
        int csh;
        scanf("%d", &csh);
        for (int j = 1; j <= n; j++){
            scanf("%d", &xc[i][j]);
            xc[i][j] += csh;
        }
        for (int j = 1; j <= m; j++){
            b[j].cd = min(b[j].cd, xc[i][b[j].le] + xc[i][b[j].ri] - 1);
        }
    }
    int tot = m;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (!che2[i][j]){
                tot++;
                b[tot].le = i;
                b[tot].ri = j;
                b[tot].cd = 1e9;
                for (int tt = 1; tt <= k; tt++)
                    b[tot].cd = min(b[tot].cd, xc[tt][i] + xc[tt][j] - 1);
            }
    sort(b + 1, b + 1 + n * (n - 1) / 2, cmp);
    memset(che, false, sizeof(che));
    int cnt = 0, ans = 0, pos = 0;
    while((cnt < (n - 1)) && (pos < (m + 10))){
        pos++;
        if (!che[b[pos].le][b[pos].ri] && !che[b[pos].ri][b[pos].le]){
            ans += b[pos].cd;
            che[b[pos].le][b[pos].ri] = che[b[pos].ri][b[pos].le] = true;
            cnt++;
            //得出哪些是联通的了
            for (int i = 1; i <= n; i++){
                if (che[i][b[pos].le])
                    che[i][b[pos].ri] = che[b[pos].ri][i] = true;
                else if (che[i][b[pos].ri])
                    che[i][b[pos].le] = che[b[pos].le][i] = true;
            }
        }
    }
    cout << ans;

    return 0;
}