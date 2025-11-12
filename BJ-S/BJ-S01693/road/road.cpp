# include <bits/stdc++.h>
using namespace std;
# define int long long
int n,m,k,ans = LONG_LONG_MAX;
int c[15];
struct node{
    int u,v,w;
} a[2000006],a1[2000006];
int b[15][10005];
bool isa = 1,d[15];
int fa[100005];             // 并查集

bool cmp(node a,node b){
    return a.w < b.w;
}

void bing(int a,int b){
    if (fa[a] == a){
        fa[a] = fa[b];
        return ;
    }
    bing(fa[a],b);
    fa[a] = fa[b];
}

bool cha(int a,int b){
    if (fa[a] == fa[b]){
        return 1;
    }
    if (fa[a] == a && fa[b] == b){
        return false;
    }
    return cha(fa[a],fa[b]);
}

int MAIN(int n,int m){
    for (int i=1;i<=m;i++){
        a1[i] = a[i];
    }
    for (int i=1;i<=n;i++){
        fa[i] = i;
    }

    sort(a1+1,a1+m+1,cmp);

    int ans = 0,add=0;
    for (int i=1;i<=m;i++){
        int u = a1[i].u,v = a1[i].v,w = a1[i].w;
        if (cha(u,v) == 0){
            ans += w;
            bing(u,v);
            add++;
        }
        else{
            continue ;
        }
        if (add == n-1) break;
    }

    return ans;
}

void dfs(int step){
    if (step > k){
        int cnt = m,cnt1=n,tot2=0;
        for (int i=1;i<=k;i++){
            if (d[i]){
                cnt1++;
                tot2 += c[i];
                for (int j=1;j<=n;j++){
                    a[++cnt] = {j,cnt1,b[i][j]};
                }
            }
        }

        ans = min(ans,MAIN(cnt1,cnt) + tot2);
        return ;
    }
    d[step] = 1;
    dfs(step+1);
    d[step] = 0;
    dfs(step+1);
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for (int i=1;i<=k;i++){
        cin >> c[i];
        bool ta = 1;
        if (c[i] != 0) isa = ta = 0;
        for (int j=1;j<=n;j++){
            cin >> b[i][j];
            if (b[i][j] != 0) isa = ta = 0;
        }
        if (ta == 1){
            cout << "0" << endl;
            return 0;
        }
    }
    if (isa){
        cout << "0" << endl;
        return 0;
    }

    dfs(1);
    cout << ans;
}
