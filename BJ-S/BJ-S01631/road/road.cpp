#include<bits/stdc++.h>
using namespace std;

int n,m,k,f[10004],c[15][10004];
struct road{
    int u;
    int v;
    int w;
}a[2000006];

bool cmp(road x,road y){
    return x.w<y.w;
}

int check(int x){
    if(f[x]==x){
        return x;
    }
    return f[x]=check(f[x]);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    for(int i=1; i<=k; i++){
        int www;
        cin >> www;
        for(int j=1; j<=n; i++){
            cin >> c[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        f[i]=i;
    }
    sort(a+1,a+m+1,cmp);
    long long b=1,money=0,r=1;
    while(b<n){
        int u=check(a[r].u),v=check(a[r].v),w=a[r].w;
        if(u!=v){
            money+=w;
            f[check(u)]=f[v];
            b++;
        }
        r++;
    }
    printf("%lld",money);

    return 0;
}
/*
4 4 0
1 4 6
4 3 4
2 4 5
2 3 7
*/
