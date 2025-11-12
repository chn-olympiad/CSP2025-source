#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[11000],use[15],c[15],w[15][11000];
long long minn=1e14,f[15],cha[15],l[15],r[15];
struct node{
    int u,v,w;
}edge[2000100];
int found(int k){
    if(fa[k]==k)return k;
    return fa[k]=found(fa[k]);
}
void UN(int u,int v){
     fa[found(u)]=found(v);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int cnt=m+(i-1)*n+j;
            edge[cnt].u=n+i;
            edge[cnt].v=j;
            cin>>edge[cnt].w;
            w[i][j]=edge[cnt].w;
        }
    }
    sort(edge+1,edge+m+k*n+1,[](node a,node b){
        return a.w<b.w;
    });
    f[0]=1e14;
    for(int i=1;i<=k;i++)use[i]=1;
    for(int i=0;i<=k;i++){
        for(int j=1;j<=k;j++)cha[j]=l[j]=r[j]=0;
        for(int j=1;j<=n+k;j++)fa[j]=j;
        long long ans=0;
        for(int j=1;j<=m+k*n;j++){
            if(edge[j].u<=n+i){
                if(edge[j].u>n and !use[edge[j].u-n])continue;
                if(found(edge[j].u)!=found(edge[j].v)){
                    if(edge[j].u>n and edge[j].u-n!=i){
                        cha[edge[j].u-n]+=w[i][edge[j].v]-edge[j].w;
                        l[edge[j].u-n]++;
                        r[edge[j].u-n]+=edge[j].w;
                    }
                    ans+=edge[j].w;
                    UN(edge[j].u,edge[j].v);
                    //cout<<"*"<<endl;
                }
            }
        }
        for(int j=1;j<i;j++){
            if(l[j]<=1){use[j]=0;ans-=r[j];}
            else if(cha[j]<c[j]){use[j]=0;ans+=cha[j];}
        }
        for(int j=1;j<=i;j++){
            if(use[j])ans+=c[j];
        }
        //cout<<ans<<endl;
        if(i==0){f[i]=ans;continue;}
        if(ans>=f[i-1]){use[i]=0;f[i]=f[i-1];}
        else {
            f[i]=ans;
            //for(int i=1;i<=)
        }
    }
    for(int i=0;i<=k;i++)minn=min(minn,f[i]);
    cout<<minn;
    return 0;
}
