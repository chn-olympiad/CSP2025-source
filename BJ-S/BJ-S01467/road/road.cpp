#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e6+6;
struct node{
    int fr, to, val;
}e[N];
int head[N], cnt, fa[N], ans=0, c[15];
bool f[15];
void add(int u, int v, int w){
    cnt++;
    e[cnt].fr=u;
    e[cnt].to=v;
    e[cnt].val=w;
}
int n, m, k, x, y, z;
bool cmp(node a, node b){
    return a.val < b.val;
}

int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
void kruscal(){
    int cnt=0;
    for(int i=1;i<=m+n*k;i++){
        if(cnt==n-1)break;
        int u=e[i].fr, v=e[i].to;
        //cout<<e[i].fr<< " " <<e[i].to<< "\n" ;

        if(Find(u)==Find(v))continue;
        fa[Find(u)]=Find(v);
        ans+=e[i].val;
        cnt++;
        //cout<<"\n"<<e[i].val<< " " <<cnt<< "\n" ;
    }
}
signed main(){
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld", &x, &y, &z);
        add(x, y, z);
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>x;
            add(n+i, j, x);
        }
    }
    sort(e+1, e+1+m+k*n, cmp);
    /*
    for(int i=1;i<=m+k*n;i++){
        cout<<e[i].fr<< " " <<e[i].to<< " " <<e[i].val<< "\n" ;
    }
    */
    kruscal();
    //if(k!=0)cout<<ans+156631163;
    cout<<ans;
    return 0;
}
