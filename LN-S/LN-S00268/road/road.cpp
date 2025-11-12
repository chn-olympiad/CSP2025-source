#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,long long>>a[10020];
vector<pair<int,long long>>b[10020];

long long c[20];
long long e[20][10010];
bool in[10020];
int fa[10010];
long long d[10020];
set<pair<long long,int>>p;
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v;
        long long w;
        scanf("%d%d%lld",&u,&v,&w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&e[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        d[i]=1e18;
        if(i==1)d[i]=0;
        p.insert({d[i],i});
    }while(!p.empty()){
        int f=(*p.begin()).second;
        long long ra=(*p.begin()).first;
        ans+=ra;
        if(fa[f]){
            b[fa[f]].push_back({f,ra});
            b[f].push_back({fa[f],ra});
        }
        p.erase(p.begin());
        in[f]=1;
        for(auto i:a[f]){
            if(d[i.first]>i.second&&!in[i.first]){
                p.erase({d[i.first],i.first});
                d[i.first]=i.second;
                p.insert({d[i.first],i.first});
                fa[i.first]=f;
            }
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            b[j].push_back({n+i,e[i][j]});
            b[n+i].push_back({j,e[i][j]});
        }
    }
    for(int j=1;j<(1<<k);j++){
        int u=n+k;
        long long s=0;
        int y=1,t=1;
        while(y<=j){
            if(y&j){
                s+=c[t];
            }y*=2;
            t++;
        }
        p.clear();
        for(int j=1;j<=u;j++){
            in[j]=0;
        }for(int i=1;i<=u;i++){
            if(i>n){
                if(!((1<<(i-n-1))&j))continue;
            }//printf("%d ",i);
            d[i]=1e18;
            if(i==1)d[i]=0;
            p.insert({d[i],i});
        }
        while(!p.empty()){//puts("S");


            int f=(*p.begin()).second;//for(auto r:p)printf("%d ",r.second);
            //printf("%d\n",f);
            long long ra=(*p.begin()).first;

            s+=ra;
            p.erase(p.begin());
            in[f]=1;
            for(auto i:b[f]){
                if(d[i.first]>i.second&&(!in[i.first])&&(i.first<=n||((1<<(i.first-n-1))&j))){
                    p.erase({d[i.first],i.first});
                    d[i.first]=i.second;
                    p.insert({d[i.first],i.first});
                }
            }
        }ans=min(ans,s);
        //printf("%d:%lld\n",j,s);
    }printf("%lld\n",ans);
    //printf("%.2f\n",clock()/1000.);
    return 0;
}
