#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1105,M=1e6+5,K=1100;
int n,m,k,b[15][N],c[15],fa[N];
vector<int> o[K];
struct edge{
    int s,e,c;
}a[M];
bool cmp(edge x,edge y){
    return x.c<y.c;
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
long long ans=1e18;
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy)fa[fx]=fy;
}
vector<edge> v[K],d[K],g;//表示在选择i时的边权序列（从小到大）
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
   scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].c);
    }
    for(int i=1;i<=k;i++){
       scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)scanf("%d",&b[i][j]);
    }
    for(int i=0;i<(1<<k);i++){
        for(int j=1;j<=k;j++){
            if(i&(1<<(j-1)))o[i].push_back(j);
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            d[i].push_back({n+i,j,b[i][j]});
        }
        sort(d[i].begin(),d[i].end(),cmp);
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    int pp=0;
    for(int i=1;i<=m;i++){
        if(find(a[i].s)!=find(a[i].e)){
            g.push_back(a[i]);
            merge(a[i].s,a[i].e);
            pp++;
            if(pp==n-1)break;
        }
    }
    int ti=0;
    for(int i=1;i<(1<<k);i++){
        int q=0;
        for(int j=1;j<=k;j++){
            if(i&(1<<(j-1))){
                q=j;
                break;
            }
        }
        int ol=(i^(1<<(q-1)));
        int l=0,r=0;
        while(l<v[ol].size()||r<d[q].size()){
            if(l==v[ol].size())v[i].push_back(d[q][r]),r++;
            else if(r==d[q].size())v[i].push_back(v[ol][l]),l++;
            else{
                if(d[q][r].c<v[ol][l].c)v[i].push_back(d[q][r]),r++;
                else v[i].push_back(v[ol][l]),l++;
            }
        }
    }
    for(int i=0;i<(1<<k);i++){
        int len=0;
        long long sum=0;
        for(int j=1;j<=k;j++)
            if(i&(1<<(j-1)))len++,sum+=c[j];
        for(int j=1;j<=n+k;j++)fa[j]=j;
        int l=0,r=0,o=0;
        //v[i],g
        while(l<v[i].size()||r<g.size()){
            edge t;
            if(l==v[i].size())t=g[r],r++;
            else if(r==g.size())t=v[i][l],l++;
            else{
                if(g[r].c<v[i][l].c)t=g[r],r++;
                else t=v[i][l],l++;
            }
            if(find(t.s)!=find(t.e)){
                merge(t.s,t.e);
                sum+=t.c;
                o++;
                if(o==n+len-1)break;
            }
        }
        ans=min(ans,sum);
    }
    printf("%lld",ans);
    return 0;
}
/*

*/
