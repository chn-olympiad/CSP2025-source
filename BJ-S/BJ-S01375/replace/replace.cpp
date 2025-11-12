#include<bits/stdc++.h>
using namespace std;
string si1[200010], si2[200010];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> si1[i] >> si2[i];
    for (int i = 1; i <= q; i++){
        string x, y;
        cin >> x >> y;
        //判断sss1是否是x的子串
        int ans = 0;
        for (int t = 1; t <= n; t++)
        for (int j = 0; j < x.size(); j++){
            if (x[j] == si1[t][0]){
                bool check = true;
                for (int k = j + 1; k < (j + si1[t].size()); k++){
                    if (x[k] != si1[t][k - j]){
                        check = false;
                        break;
                    }
                }
                if (!check)
                    continue;
                string tmp = x;
                for (int k = j; k < (j + si1[t].size()); k++)
                    tmp[k] = si2[t][k - j];
                if (tmp == y)
                    ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}