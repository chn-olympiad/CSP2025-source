#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int maxx[100005],smaxx[100005];
vector<int> v[5];
bool cmp(int a,int b) {
    return maxx[a] - smaxx[a] > maxx[b] - smaxx[b];
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int ans = 0;
        for(int i = 1;i <= 3;i++) v[i].clear();
        for(int i = 1;i <= n;i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            maxx[i] = max(max(a[i][1],a[i][2]),a[i][3]);
            if(maxx[i] == a[i][1]) {v[1].push_back(i);smaxx[i] = max(a[i][2],a[i][3]);}
            if(maxx[i] == a[i][2]) {v[2].push_back(i);smaxx[i] = max(a[i][1],a[i][3]);}
            if(maxx[i] == a[i][3]) {v[3].push_back(i);smaxx[i] = max(a[i][2],a[i][1]);}
            ans += maxx[i];
        }
        for(int i = 1;i <= 3;i++) {
            if(v[i].size() > n / 2) {
                sort(v[i].begin(),v[i].end(),cmp);
                for(int j = n / 2;j < v[i].size();j++) {
                    ans -= maxx[v[i][j]] - smaxx[v[i][j]];
                    //cout << v[i][j] << endl;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
