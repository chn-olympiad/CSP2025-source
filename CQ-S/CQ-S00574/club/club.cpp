#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
struct stu{
    pi zd, cd;
}sz[100010];
bool cmp(stu x, stu y){
    // if(x.zd.second == y.zd.second){
        return x.zd.first + y.cd.first > x.cd.first + y.zd.first;
    // }
    // return x.zd.first > y.zd.first;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            pi zd={-1, -1}, cd={-1, -1};
            for(int j=1;j<=3;j++){
                int a;
                cin >> a;
                if(a > zd.first){
                    cd = zd;
                    zd = {a, j};
                } else if(a > cd.first){
                    cd = {a, j};
                }
            }
            sz[i].zd = zd;
            sz[i].cd = cd;
        }
        sort(sz+1, sz+1+n, cmp);
        int js[5]={};
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(js[sz[i].zd.second] >= n/2){
                ans += sz[i].cd.first;
                js[sz[i].cd.second]++;
            } else {
                ans += sz[i].zd.first;
                js[sz[i].zd.second]++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}