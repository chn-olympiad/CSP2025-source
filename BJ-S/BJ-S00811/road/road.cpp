#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge{
    int u,v,w;
};
vector<Edge> g,t;
int c[15];
int a[15][100005];
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
int f[100105],sz[100105];
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
bool merge(int x,int y){
    int t1=find(x),t2=find(y);
    if(t1==t2) return 0;
    if(sz[t1]<sz[t2]){
        f[t1]=t2;
        sz[t2]+=sz[t1];
    }
    else{
        f[t2]=t1;
        sz[t1]+=sz[t2];
    }
    return 1;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g.push_back({u,v,w});
    }
    bool flag=1;
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(c[i]!=0) flag=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(!flag){
        long long ans=9e18;
        for(int st=0;st<(1<<k);st++){
            long long sum=0;
            t=g;
            for(int i=1;i<=n+10;i++){
                f[i]=i;
                sz[i]=1;
            }
            int cnt=n;
            //printf("K: ");
            for(int i=1;i<=k;i++){
                if((st>>(i-1))&1){
                    //printf("%d ",i);
                    sum+=c[i];
                    cnt++;
                    for(int j=1;j<=n;j++){
                        t.push_back({cnt,j,a[i][j]});
                    }
                }
            }
            //printf("\ncnt:%d\n",cnt);
            sort(t.begin(),t.end(),cmp);
            //for(auto e:t){
            //    printf("%d %d %d\n",e.u,e.v,e.w);
            //}
            for(auto e:t){
                bool lcz=merge(e.u,e.v);
                if(lcz){
                    sum+=e.w;
                    //printf("ASD%d %d %d\n",e.u,e.v,e.w);
                }
                cnt-=lcz;
                if(cnt==0) break;
            }
            //printf("Sum:%d\n",sum);
            ans=min(ans,sum);
        }
        printf("%lld",ans);
    }
    else{
        long long ans=0;
        for(int i=1;i<=n+k;i++){
            f[i]=i;
            sz[i]=1;
        }
        int cnt=n+k;
        //printf("K: ");
        for(int i=1;i<=k;i++){
                //printf("%d ",i);
            for(int j=1;j<=n;j++){
                g.push_back({n+i,j,a[i][j]});
            }
        }
        //printf("\ncnt:%d\n",cnt);
        sort(g.begin(),g.end(),cmp);
        //for(auto e:t){
        //    printf("%d %d %d\n",e.u,e.v,e.w);
        //}
        for(auto e:g){
            bool lcz=merge(e.u,e.v);
            if(lcz){
                ans+=e.w;
                //printf("ASD%d %d %d\n",e.u,e.v,e.w);
            }
            cnt-=lcz;
            if(cnt==0) break;
        }
        //printf("Sum:%d\n",sum);
        printf("%lld",ans);
    }
    return 0;
}
