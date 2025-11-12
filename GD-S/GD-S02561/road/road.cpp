#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+1e4+20;
int n,m,k;
int c[N],cost[20][N];
int fa[N];//并查集数组
struct road
{
    int u,v,w;
}a[N];

bool cmp(road x,road y){return x.w<y.w;}

int get(int x){
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
}

ll Kruskal(){
    for(int i=1;i<=n+k;i++)fa[i]=i;

    ll cnt=0,sum=0;
    for(int i=1;i<=m+n*k;i++){//遍历每一条边
        if(cnt==n-1)break;//n条边，已经构成一棵树
        int u=a[i].u,v=a[i].v,w=a[i].w;
        
        if(get(u)==get(v))continue;//两点已经联通，没有必要再添加一条边了
        cnt++;
        sum+=w;
        fa[get(u)]=get(v);//连接两点
    }
    return sum;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    
    int p=n;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        p++;
        for(int j=1,price;j<=n;j++){
            cin>>price;
            int tmp=m+(i-1)*n+j;
            a[tmp].u=p,a[tmp].v=j,a[tmp].w=price;
        }
    }

    sort(a+1,a+1+n,cmp);

    cout<<Kruskal()<<'\n';
    return 0;
}
