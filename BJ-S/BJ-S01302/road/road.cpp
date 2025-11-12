#include<bits/stdc++.h>
using namespace std;

#define re register
const int N=1e4+10,M=1e6+10;
struct X{
    int u,v,w;
}a[M],b[N*15];
bool cmp(X a,X b){
    return a.w<b.w;
}
int fa[N+1];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int n,m,k,c[N];
int t;
long long ans;
int count(int x){
    int cnt=0;
    while(x){
        x-=x&-x;
        cnt++;
    }
    return cnt;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(re int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+m+1,cmp);
    for(re int i=1;i<=n;i++)fa[i]=i;
    for(re int i=1,x,y,cnt=0;i<=m;i++){
        x=find(a[i].u);
        y=find(a[i].v);
        if(x==y)continue;
        fa[x]=y;
        ans+=a[i].w;
        b[++t]=a[i];
        cnt++;
        if(cnt==n-1)break;
    }
    for(re int i=1;i<=k;i++){
        cin>>c[i];
        for(re int j=1;j<=n;j++){
            cin>>b[++t].w;
            b[t].u=i+n;
            b[t].v=j;
        }
    }
    sort(b+1,b+t+1,cmp);
    for(re int i=1;i<(1<<k);i++){
        long long sum=0;
        for(re int j=1;j<=k;j++){
            if((i>>j-1)&1)sum+=c[j];
        }
        if(sum>=ans)continue;
        for(re int j=1;j<=n+k;j++)fa[j]=j;
        int v=count(i)+n;
        for(re int j=1,cnt=0;j<=t&&cnt<v;j++){
            int u=b[j].u,v=b[j].v,w=b[j].w;
            if(u>n&&!((i>>(u-n-1))&1))continue;
            u=find(u);
            v=find(v);
            if(u==v)continue;
            fa[u]=v;
            sum+=w;
            cnt++;
            if(sum>=ans)break;
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
