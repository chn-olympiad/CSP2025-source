#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e4+15, maxm=1e6+1e5+5;
int n, m, k, a[maxn];
bool check[maxn];

struct node{
    int u, v, w;
}e[maxm];
int h[maxn];

int _find(int x){
    return h[x]==x? x: h[x]=_find(h[x]);
}

void merge(int x, int y){
    x=_find(x), y=_find(y);
    h[x]=y;
}

bool cmp(node x, node y){
    return x.w<y.w;
}

ll mst(){
    for (int i=1;i<=n+k;i++) h[i]=i;

    sort(e+1, e+m+1, cmp);

    ll sum=0;
    for (int i=1;i<=m+k*n;i++){
        int x=e[i].u, y=e[i].v;
        if (_find(x)==_find(y)) continue;
        if (!check[x]) sum+=a[x-n];
        merge(x, y);
        sum+=e[i].w;
    }

    return sum;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    bool flag=true;
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        e[i].u=u, e[i].v=v, e[i].w=w;
    }
    for (int i=1;i<=k;i++){
        cin>>a[i];
        for (int j=1;j<=n;j++){
            int x; cin>>x;
            int ind=i*(n+1)+m+j-n-1;
            e[ind].u=i+n, e[ind].v=j, e[ind].w=x;
        }
        if (a[i]!=0) flag=false;
    }

    ll sum=mst();

    cout<<sum<<endl;
    return 0;

    fclose(stdin);
    fclose(stdout);
}