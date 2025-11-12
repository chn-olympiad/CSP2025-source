#include <bits/stdc++.h>
using namespace std;

struct st{
    int a, b, c;
}a[100010];
int ord[100010][4];
vector<int> v[4];
bool cmp1(const int &x, const int &y){
    return ord[x][1] < ord[y][1];
}
bool cmp2(const int &x, const int &y){
    return ord[x][2] < ord[y][2];
}
bool cmp3(const int &x, const int &y){
    return ord[x][3] < ord[y][3];
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        v[1].clear(); v[2].clear(); v[3].clear();
        for(int i = 1; i <= n; i++){
            cin >> a[i].a >> a[i].b >> a[i].c;
            int maxn = max({a[i].a, a[i].b, a[i].c});
            ans += maxn;
            if(maxn == a[i].a){
                v[1].push_back(i);
                ord[i][1] = a[i].a - max(a[i].b, a[i].c);
                ord[i][2] = a[i].b - a[i].c;
                ord[i][3] = a[i].c - a[i].b;
            }else if(maxn == a[i].b){
                v[2].push_back(i);
                ord[i][2] = a[i].b - max(a[i].a, a[i].c);
                ord[i][1] = a[i].a - a[i].c;
                ord[i][3] = a[i].c - a[i].a;
            }else{
                v[3].push_back(i);
                ord[i][3] = a[i].c - max(a[i].b, a[i].a);
                ord[i][2] = a[i].b - a[i].a;
                ord[i][1] = a[i].a - a[i].b;
            }
            if(ord[i][1] < 0){
                ord[i][1] = 1e9;
            }
            if(ord[i][2] < 0){
                ord[i][2] = 1e9;
            }
            if(ord[i][3] < 0){
                ord[i][3] = 1e9;
            }
        }
        if(v[1].size() > n / 2){
            sort(v[1].begin(), v[1].end(), cmp1);
            for(int i = 0; i < v[1].size() - n / 2; i++){
                ans -= ord[v[1][i]][1];
            }
        }else if(v[2].size() > n / 2){
            sort(v[2].begin(), v[2].end(), cmp2);
            for(int i = 0; i < v[2].size() - n / 2; i++){
                ans -= ord[v[2][i]][2];
            }
        }else if(v[3].size() > n / 2){
            sort(v[3].begin(), v[3].end(), cmp3);
            for(int i = 0; i < v[3].size() - n / 2; i++){
                ans -= ord[v[3][i]][3];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}