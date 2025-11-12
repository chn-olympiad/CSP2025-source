#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

array<int,3> t[20][100010],a[1000010],sps[1000010],fn[1000010];
int c[20],dp[1024],dsu[100050],cnt[100050];
i64 cntv[1024];

bool cmp(const array<int,3> &x,const array<int,3> &y){return x[2] < y[2];}

int findset(int x){return dsu[x] == x?x:dsu[x] = findset(dsu[x]);}

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 1;i <= m;i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    sort(a + 1,a + m + 1,cmp);

    for (int i = 1;i <= k;i++){
        cin >> c[i];
        for (int j = 1;j <= n;j++){
            cin >> t[i][j][2];
            t[i][j][0] = n + i,t[i][j][1] = j;
        }

        sort(t[i] + 1,t[i] + n + 1,cmp);
    }

    i64 ans = 0;

    for (int i = 1;i <= n;i++)
        dsu[i] = i,cnt[i] = 1;

    for (int i = 1;i < 1 << k;i++)
        cntv[i] = cntv[i - (i & -i)] + c[__lg(i & -i) + 1];

    vector<array<int,3>> edgs;

    for (int i = 1;i <= m;i++){
        int x = findset(a[i][0]),y = findset(a[i][1]);
        if (x != y){
            edgs.push_back(a[i]);
            if (cnt[x] < cnt[y]) swap(x,y);

            ans += a[i][2];
            dsu[y] = x,cnt[x] += cnt[y];
        }
    }

    m = 0;
    for (auto i:edgs)
        a[++m] = i;

    for (int i = 1 << k;--i;){
        i64 nans = 0;

        int top = 0;

        for (int j = 1;j <= k;j++)
            if (i & 1 << j - 1){
                merge(fn + 1,fn + top + 1,t[j] + 1,t[j] + n + 1,sps + 1,cmp);

                top += n;

                for (int k = 1;k <= top;k++)
                    fn[k] = sps[k];
            }

        merge(fn + 1,fn + top + 1,a + 1,a + m + 1,sps + 1,cmp);

        top += m;

        for (int k = 1;k <= top;k++)
            fn[k] = sps[k];

        for (int i = 1;i <= n + k;i++)
            dsu[i] = i,cnt[i] = 1;

        for (int j = 1;j <= top;j++){
            int x = findset(fn[j][0]),y = findset(fn[j][1]);

            if (x != y){
                nans += fn[j][2];

                if (nans >= ans) break;

                if (cnt[x] < cnt[y]) swap(x,y);

                dsu[y] = x,cnt[x] += cnt[y];
            }
        }

        ans = min(ans,nans + cntv[i]);
    }

    cout << ans;
}
