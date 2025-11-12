#include <bits/stdc++.h>
using namespace std;
long long parent[1000001];
long long FIND(long long x){
    if(parent[x]==x)return x;
    else
        return parent[x]=FIND(parent[x]);
}
void add(long long x,long long y){
    if(FIND(x)==FIND(y))return ;
    parent[y]=x;
    return ;
}
struct S{
    long long u,v,w;
}a[1000001];
bool cmp(S x,S y){
    if(x.w<y.w)return true;
    return false;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
    int cnt=m;
    for(int j=1;j<=k;j++){
            long long as2;
        cin>>as2;
        for(int i=1;i<=n;i++){
            a[cnt].u=j;a[cnt].v=i;
            cin>>a[cnt].w;
            cnt++;
        }
    }
    long long sum=0,ans=0;
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        long long u=FIND(a[i].u);
        long long v=FIND(a[i].v);
        long long w=a[i].w;
        if(u==v)continue;
        parent[v]=u;
        ans++;
        sum+=w;
        if(ans==n-1)break;
    }
    cout<<sum;
    return 0;
}
