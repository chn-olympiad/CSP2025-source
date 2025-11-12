#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;
int T, n, limit;
struct S{
    vector<int> a;
    int minn = INT_MAX;

    void jisuan(int t){
        for (int i = 0; i < 3; i++){
            if (i == t) continue;
            minn = min(minn, a[t]-a[i]);
        }
    }
} arr[N];


vector<vector<int>> cnt(3);


int gm(int i){
    int maxn = arr[i].a[0], res = 0;
    for (int j = 1; j <= 2; j++){
        if (maxn < arr[i].a[j]) {
            maxn = arr[i].a[j];
            res = j;
        }
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> T;
    while (T--){
        cnt.clear();
        cnt.resize(3);
        int res = 0;
        cin >> n;
        limit = n/2;
        for (int i = 0; i <= n;i++){
            arr[i].minn = INT_MAX;
            arr[i].a.clear();
        }
        for (int i = 0; i < n; i++){
            arr[i].a.resize(3);
            cin >> arr[i].a[0] >> arr[i].a[1] >> arr[i].a[2];
        }
        for (int i = 0; i < n; i++){
            int ch = gm(i);
            cnt[ch].push_back(i);
            res += arr[i].a[ch];
            arr[i].jisuan(ch);
        }
        int lot = -1;
        for (int i = 0; i < 3; i++){
                //cout << (int)cnt[i].size() - limit << endl;;
            if ((int)cnt[i].size() - limit > 0){
                lot = i;
                break;
            }
        }
        if (lot != -1){
            sort(cnt[lot].begin(), cnt[lot].end(), [&](int a, int b){
                return arr[a].minn < arr[b].minn;
                });
                //cout << cnt[lot].size() - limit << endl;
            for (int i = 0; i < (int)cnt[lot].size() - limit; i++){
                res -= arr[cnt[lot][i]].minn;
            }
        }

        cout << res << endl;
    }
    return 0;
}
/*

*/
/*
3
4
0 1 0
0 1 0
0 2 0
0 2 0
4
}
*/
