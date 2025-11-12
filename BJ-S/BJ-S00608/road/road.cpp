#include <bits/stdc++.h>
using namespace std;
struct S{
    int u, v, w;
    bool operator<(S& other){
        return this->w < other.w;
    }
}a[1000005];
int b[10015];
int getfa(int n){
    if (b[n]==n) return n;
    return b[n]=getfa(b[n]);
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k, ans=0, f=0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i=1; i<=n+k; ++i) b[i]=i;
    for (int i=0; i<m; ++i)
        scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
    sort(a, a+m);
    for (int i=0; i<m&&f<n-1; ++i){
        if (getfa(a[i].u)!=getfa(a[i].v)){
            ans+=a[i].w;
            b[getfa(a[i].v)]=getfa(a[i].u);
            ++f;
        }
    }
    printf("%d", ans);
    return 0;
}
