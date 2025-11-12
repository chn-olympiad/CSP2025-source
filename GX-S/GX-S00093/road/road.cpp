#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans = 0,cnt[12000010][3];
vector<long long> e,h,f[12000010],f2[12000010];
bool flag;
inline void clec(){
    e.push_back(1);
    memset(cnt,127,sizeof(cnt));
    cnt[1][1] = cnt[1][2] = 0;
    while (true){
        flag = false;
        h.clear();
        for (auto x : e){
            for (long long i = 0;i < f[x].size();i++){
                if (cnt[f[x][i]][1] > cnt[x][1] + f2[x][i]){
                    long long y = cnt[f[x][i]][2];
                    if (y > 1 << 62) y = 0;
                    ans -= y,ans += f2[x][i],cnt[f[x][i]][2] = f2[x][i];
                    flag = true;
                    h.push_back(f[x][i]);
                }
            }
        }
        e.clear();
        for (auto y : h) e.push_back(y);
        if (!flag) break;
    }
    cout << ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    long long x,y,z;
    while (m--)
        scanf("%lld%lld%lld",&x,&y,&z),f[x].push_back(y),f[y].push_back(x),f2[x].push_back(z),f2[y].push_back(z);
    clec();
    return 0;
}
