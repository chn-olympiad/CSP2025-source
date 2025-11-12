#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+1,M = 1e6+1;
int n , m , k;
struct eg{
    int u , v , w;
}l[M*4];
int c[N][11];
int k1[11];
bool cmp(eg s1 , eg s2){
    return s1.w <s2.w;
}
long long ans;
int f[N];

int fi(int x){
    if(f[x] == x)
        return x;
    else{
      return  f[x] = fi(f[x]);

    }
}
long long tot;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m; i++){
            tot++;
        cin >> l[tot].u >> l[tot].v >> l[tot].w;
        tot++;
        l[tot].v = l[tot-1].u , l[tot].u = l[tot-1].v , l[tot].w = l[tot-1].w;

    }
    for(int i = 1; i <= n; i++)
        f[i] = i;
    if(k){
    for(int i = 1; i <= k; i++){
        cin >> k1[i];
        for(int j = 1;j <= n; j++){
            cin >> c[j][i];
            c[j][i] += k1[i];
        }
    }
    for(int k11 = 1; k11 <= k; k11++){
        for(int i = 1; i <= n; i++)
            for(int j = i+1; j <= n; j++){
                    l[++tot].u = i , l[tot].v = j ;
                    l[tot].w = c[i][k11] + c[j][k11] - k1[k11];
                    l[++tot].u = j , l[tot].v = i ;
                     l[tot].w = c[i][k11] + c[j][k11] - k1[k11];

        }
    }

    }
    sort(l+1,l+tot+1,cmp);
    int fl = 0;
    for(int i = 1; i <= tot; i++){
        int u1 = l[i].u , v1 = l[i].v;
        int fu = fi(u1) , fv = fi(v1);
        if(fu == fv)
            continue;
        f[v1] = fu;
        ans += l[i].w;
        fl++;

        if(fl == n-1)
            break;

    }

    cout <<ans;

    return 0;
}
