#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ee{
    int u, v, w;
};
int head[10005], cnt=0, parents[10005], r[10005], kk[12], a[12][10005];
void init(int n){
    for(int i=1;i<=n;i++){
        parents[i] = i;
        r[i] = 0;
    }
}

int fd(int node){
    return parents[node] == node ? node : parents[node] = fd(parents[node]);
}

void mg(int n1, int n2){
    int f1 = fd(n1);
    int f2 = fd(n2);
    if(r[f1] > r[f2]){
        parents[f2] = f1;
    }else{
        parents[f1] = f2;
        if(r[f1] == r[f2]) r[f1]++;
    }
}

signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k, u, v, w;
    cin >> n >> m >> k;
    vector<ee> eee;
    for(int i=0;i<m;i++){
        cin >> u >> v >> w;
        eee.push_back({u, v, w});
    }
    for(int i=1;i<=k;i++){
        cin >> kk[i];
        for(int ii=1;ii<=n;ii++){
            cin >> a[i][ii];
        }
    }
    sort(eee.begin(), eee.end(), [](ee a, ee b){return a.w < b.w;});
    int ccc=0, sumw=0, ans;
    init(n);
    for(int i=0;i<m;i++){
        if(fd(eee[i].u) != fd(eee[i].v)){
            mg(eee[i].u, eee[i].v);
            sumw += eee[i].w;
        }else{
            continue;
        }
    }
    ans = sumw;
    for(int t=1;t<pow(2, k);t++){
        sumw = 0;ccc=0;
        vector<ee> eeee(eee);
        for(int i=1;i<=k;i++){
            bool has_k = t & (1 << (i-1));
            sumw += (has_k) * kk[i];
            if(i % 2 == 1){
                for(int uu=1;uu<=n;uu++){
                    for(int vv=uu+1;vv<=n;vv++){
                        eeee.push_back({uu, vv, a[i][uu] + a[i][vv]});
                    }
                }
            }
        }
        sort(eeee.begin(), eeee.end(), [](ee a, ee b){return a.w < b.w;});
        init(n);
        for(int i=0;i<eeee.size();i++){
            if(fd(eeee[i].u) != fd(eeee[i].v)){
                mg(eeee[i].u, eeee[i].v);
                sumw += eeee[i].w;
            }else{
                continue;
            }
        }
        ans = min(ans, sumw);
    }
    cout << ans << endl;
}

