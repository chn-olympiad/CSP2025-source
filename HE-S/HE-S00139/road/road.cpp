#include <bits/stdc++.h>
using namespace std;

struct edge{

    int u, v;
    long long w;
    bool operator < (edge A) const{
        return w<A.w;
    }

};

int n, m, k;
vector <edge> e;
long long a[1010];
int f[1010];

int ff(int x){

    if(f[x]==x){
        return x;
    }
    return f[x]=ff(f[x]);

}

int main(){

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; i++){
        int u, v;
        long long w;
        scanf("%d%d%lld", &u, &v, &w);
        e.push_back({u, v, w});
    }
    for(int i=1; i<=k; i++){
        long long c;
        scanf("%lld", &c);
        for(int j=1; j<=n; j++){
            scanf("%lld", &a[j]);
        }
        for(int j=1; j<n; j++){
            for(int l=j+1; l<=n; l++){
                e.push_back({j, l, c+a[j]+a[l]});
                m++;
            }
        }
    }
    sort(e.begin(), e.end());
    for(int i=1; i<=n; i++){
        f[i]=i;
    }
    long long ans=0;
    int cnt=1;
    for(int i=0; i<m && cnt<=n-1; i++){
        int x=e[i].u, y=e[i].v;
        long long w=e[i].w;
        int fx=ff(x), fy=ff(y);
        if(fx!=fy){
            f[fx]=fy;
            ans+=w;
            cnt++;
        }
    }
    printf("%lld\n", ans);

    return 0;

}
