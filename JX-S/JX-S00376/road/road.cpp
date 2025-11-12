#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 2e6 + 10;
int n,m,k,c[N],b[20][10010],fa[N],siz[N],sum,minn = 1e18,l,ans;
struct node{
    int u,v,w;
}a[N],f[N];
int find(int x){
    while(x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}
bool g;
bool cmp(node x,node y){
    return x.w < y.w;
}
void bing(int x,int y,int w){
    x = find(x),y = find(y);
    if (x == y) return ;
    ans+=w;
    sum++;
    if (siz[x] > siz[y]) fa[y] = x,siz[x]+=siz[y];
    else fa[x] = y,siz[y]+=siz[x];
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> a[i].u >> a[i].v >> a[i].w;
    for (int i = 1; i <= k; i++){
        cin >> c[i];
        bool f = 0;
        for (int j = 1; j <= n; j++){
            cin >> b[i][j];
            if (b[i][j] == 0) f = 1;
        }
        if (f == 0 || c[i] > 0) g = 1; 
    }
    sort(a+1,a+m+1,cmp);
    if (g == 0){
        for (int j = 1; j <= n+k; j++) fa[j] = j,siz[j] = 1;
        for (int i = 1; i <= k; i++){
            for (int j = 1; j <= n; j++){
                a[++m] = node{n+i,j,b[i][j]};
            }
        }
        sort(a+1,a+m+1,cmp);
        for (int i = 1; i <= m; i++){

            bing(a[i].u,a[i].v,a[i].w);
        }
        cout << ans;
        return 0;
    }
    for (int i = 0; i < (1 << k); i++){ 
        for (int j = 1; j <= n+k; j++) fa[j] = j,siz[j] = 1;
        for (int j = 1; j <= l; j++) f[j].u = f[j].v = f[j].w = 0;
        ans = 0,l = 0;
        for (int j = 1; j <= k; j++){
            if ((i&(1 << (k - j))) > 0){
                ans+=c[j];
                for (int s = 1; s <= n; s++){
                    f[++l] = node{n+j,s,b[j][s]};
                }
            }
        }
        sort(f+1,f+l+1,cmp);
        for (int l1 = 1,l2 = 1; l1 <= m; l1++){
            while(l2 <= l && f[l2].w <= a[l1].w) bing(f[l2].u,f[l2].v,f[l2].w),l2++;
            bing(a[l1].u,a[l1].v,a[l1].w);
        }
        minn = min(minn,ans);
    }
    cout << minn;
    return 0;
}