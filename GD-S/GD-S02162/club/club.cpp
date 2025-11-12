#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
int a[maxn][6];
vector<int>val[4];
bool cmp(int nx, int ny){
    return a[nx][a[nx][4]] - a[nx][a[nx][5]] > a[ny][a[ny][4]] - a[ny][a[ny][5]];
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++){
        	int id = -1, id2 = -1;
            for(int j = 1;j <= 3;j++){
                cin >> a[i][j];
                if(id == -1 || a[i][j] > a[i][id]) id = j;
            }
            val[id].push_back(i);
            for(int j = 1;j <= 3;j++){
                if((id2 == -1 || a[i][j] > a[i][id2]) && j != id) id2 = j;
            }
            a[i][4] = id, a[i][5] = id2;
        }
        int ans = 0;
        for(int i = 1;i <= 3;i++){
            int siz = val[i].size();
            if(siz > n / 2){
                sort(val[i].begin(), val[i].end(), cmp);
                for(int j = siz - 1;j >= n / 2;j--) ans += a[val[i][j]][a[val[i][j]][5]];
                for(int j = 0;j < n / 2;j++) ans += a[val[i][j]][a[val[i][j]][4]];
                val[i].clear();
                continue;
            }
            for(auto v : val[i]) ans += a[v][a[v][4]];
            val[i].clear();
        }
        cout << ans << "\n";
    }
    return 0;
}

