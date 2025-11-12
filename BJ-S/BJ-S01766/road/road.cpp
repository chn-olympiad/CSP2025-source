#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
const int MAXN = 11005,MAXLGK = 15,MAXK = 1105,MAXM = 1000005;
const long long inf = 1e18;
int n,m,K,a[MAXLGK],fa[MAXN],siz[MAXN],etop[MAXK];
array <int,3> e0[MAXM],e1[MAXLGK][MAXN],ef[MAXK][MAXN],enow[MAXN << 1];
inline void build(){
    for(int i = 1;i <= n + K;i++){
        fa[i] = i;
        siz[i] = 1;
    }
}
inline int getfa(int pos){
    return (pos == fa[pos]) ? pos : (fa[pos] = getfa(fa[pos]));
}
inline bool mrg(int pos1,int pos2){
    pos1 = getfa(pos1);
    pos2 = getfa(pos2);
    if(pos1 == pos2){
        return 0;
    }
    if(siz[pos1] < siz[pos2]){
        swap(pos1,pos2);
    }
    siz[pos1] += siz[pos2];
    fa[pos2] = pos1;
    return 1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> K;
    for(int i = 1;i <= m;i++){
        cin >> e0[i][1] >> e0[i][2] >> e0[i][0];
    }
    sort(e0 + 1,e0 + 1 + m);
    for(int i = 1;i <= K;i++){
        cin >> a[i];
        for(int j = 1;j <= n;j++){
            cin >> e1[i][j][0];
            e1[i][j][1] = n + i;
            e1[i][j][2] = j;
        }
        sort(e1[i] + 1,e1[i] + 1 + n);
    }
    build();
    for(int i = 1;i <= m;i++){
        if(mrg(e0[i][1],e0[i][2])){
            ef[0][++etop[0]] = e0[i];
        }
    }
    for(int i = 1;i < (1 << K);i++){
        int lowb;
        for(int j = 0;j < K;j++){
            if((i >> j) & 1){
                lowb = j;
                break;
            }
        }
        int fro = i ^ (1 << lowb);
        merge(ef[fro] + 1,ef[fro] + 1 + etop[fro],e1[lowb + 1] + 1,e1[lowb + 1] + 1 + n,enow + 1);
        build();
        for(int j = 1;j <= etop[fro] + n;j++){
            if(mrg(enow[j][1],enow[j][2])){
                ef[i][++etop[i]] = enow[j];
            }
        }
    }
    long long ans = 1e18;
    for(int i = 0;i < (1 << K);i++){
        long long sum = 0;
        for(int j = 0;j < K;j++){
            if((i >> j) & 1){
                sum += a[j + 1];
            }
        }
        for(int j = 1;j <= etop[i];j++){
            sum += ef[i][j][0];
        }
        ans = min(ans,sum);
    }
    cout << ans;
    return 0;
}
