#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[15];
struct road{
    int u;
    int v;
    int w;
}t[1000006],t1[15][10004],t2[200005];
int bz[100005];
int f[10014];
int find(int x){
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}bool cmp(road &i,road &j){
    return i.w<j.w;
}int su[15];
long long ans=0;
int main(){
    freopen("road4.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&t[i].u,&t[i].v,&t[i].w);
    }
    sort(t+1,t+1+m,cmp);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }long long ans=0;
    for(int i=1;i<=m;i++){
        if(find(t[i].u)!=find(t[i].v)){
            bz[++bz[0]]=i;
            f[find(t[i].u)]=f[t[i].v];
            ans+=t[i].w;
            if(bz[0]>=n-1)break;
        }
    }
    for(int i=1;i<n;i++){
        t[i].u=t[bz[i]].u;
        t[i].v=t[bz[i]].v;
        t[i].w=t[bz[i]].w;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&a[i]);
        for(int j=1;j<=n;j++){
            t1[i][j].u=i+n;
            t1[i][j].v=j;
            scanf("%d",&t1[i][j].w);
        }
    }
    int K=(1<<k);
    long long ans1;
    for(int i=1;i<K;i++){
        ans1=0;
        for(int j=1;j<n;j++){
            t2[j].u=t[j].u;
            t2[j].v=t[j].v;
            t2[j].w=t[j].w;
        }int sum=n-1;
        su[0]=0;
        for(int j=1;j<=k;j++){
            if(i&(1<<(j-1))){
                su[++su[0]]=j;
                ans1+=a[j];
                for(int z=1;z<=n;z++){
                    ++sum;
                    t2[sum].u=t1[j][z].u;
                    t2[sum].v=t1[j][z].v;
                    t2[sum].w=t1[j][z].w;
                }
            }
        }
        if(ans1>=ans)continue;
        sort(t2+1,t2+1+sum,cmp);
        for(int i=1;i<=n+k;i++){
            f[i]=i;
        }
        int ne=n+su[0]-1;
        for(int j=1;j<=sum;j++){
            if(find(t2[j].u)!=find(t2[j].v)){
                f[find(t2[j].u)]=f[t2[j].v];
                ans1+=t2[j].w;
                ne--;
                if(ans1>=ans)break;
                if(ne<=0)break;
            }
        }
        ans=min(ans,ans1);
    }
    printf("%lld",ans);
    return 0;
}