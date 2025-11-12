#include <bits/stdc++.h>
using namespace std;
long long n,m,k,cnt,ans,cnt2,f[20010],c[20],cnt3[20],f2[100010];
bool vis[20],t[10010];
struct node{
    long long u,v,dis;
    bool friend operator <(node a,node b){
        return a.dis<b.dis;
    }
}edge[3000010],q[20][10010];
int find(int x){
    if(x==f[x])
        return x;
    return f[x]=find(f[x]);
}
int find2(int x){
    if(x==f2[x])
        return x;
    return f2[x]=find(f2[x]);
}
void kk(){
    sort(edge+1,edge+1+n*k+m);/*
    for(long long i=1;i<=m+n*k;i++){
        long long x=edge[i].u,y=edge[i].v,w=edge[i].dis;
        cout<<x<<" "<<y<<" "<<w<<"\n";
    }cout<<"\n";*/
    for(long long i=1;i<=m+n*k;i++){
        long long x=edge[i].u,y=edge[i].v,w=edge[i].dis;
        if(x<y)
            swap(x,y);
        if(find(x)==find(y))
            continue;
        f[find(x)]=find(y);

        if(x>n){
            if(!vis[x]){
                vis[x]=1;
            }
            else
                ans-=c[x-n];
            cnt3[x-n]++;
            q[x-n][cnt3[x-n]]=edge[i];
        }
        ans+=w;
        //cout<<x<<" "<<y<<" "<<w<<"\n";
        if(++cnt2==n+k-1)
            return;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)
        f[i]=i;
       for(int i=1;i<=n;i++)
        f2[i]=i;
    for(long long i=1;i<=m;i++){
        long long x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        edge[i]={x,y,z};
    }
    cnt=m;
    for(long long i=1;i<=k;i++){
        cin>>c[i];
        for(long long j=1;j<=n;j++){
            long long x;
            scanf("%lld",&x);
            edge[++cnt]={i+n,j,c[i]+x};
        }
    }
    kk();

    for(int i=1;i<=k;i++){
        if(cnt3[i]==1)
            ans-=q[i][1].dis;//,cout<<i<<" "<<q[i][1].dis<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}

