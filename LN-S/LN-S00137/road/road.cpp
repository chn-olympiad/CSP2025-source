#include <bits/stdc++.h>
using namespace std;
long long n,m,k,p[3000005];
bool sp1=1,v[3000006];
struct edge{
    long long u,v,w;
}ed[3000006];
long long c[15][300005];
bool cmp(edge u,edge v){
    return u.w<v.w;
}
long long find(long long x){
    if(p[x]!=x){
        p[x]=find(p[x]);
    }
    return p[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>ed[i].u>>ed[i].v>>ed[i].w;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>c[i][j];
        }
        if(c[i][0]!=0){
            sp1=0;
        }
    }
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    if(k==0){
        sort(ed+1,ed+m+1,cmp);
        long long cnt(0ll),ans(0ll);
        for(int i=1;i<=m;i++){
            if(find(ed[i].u)!=find(ed[i].v)){
                p[find(ed[i].v)]=find(ed[i].u);
                cnt++;
                ans+=ed[i].w;
                if(cnt==n-1){
                    break;
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(sp1){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(c[i][j]==0){
                    for(int h=1;h<=n;h++){
                        if(j==h){
                            continue;
                        }
                        ed[++m].u=j;
                        ed[m].v=h;
                        ed[m].w=c[i][h];
                    }
                    break;
                }
                // ed[++m].u=i;
                // ed[m].v=j;
                // ed[m].w=c[i][j];
            }
        }
        sort(ed+1,ed+m+1,cmp);
        long long cnt(0ll),ans(0ll);
        for(int i=1;i<=m;i++){
            if(find(ed[i].u)!=find(ed[i].v)){
                p[find(ed[i].v)]=find(ed[i].u);
                cnt++;
                ans+=ed[i].w;
                if(cnt==n-1){
                    break;
                }
            }
        }
        cout<<ans;
        return 0;
    }
    long long nn=n,mm=m;
    for(int i=1;i<=k;i++){
        nn++;
        for(int j=1;j<=n;j++){
            ed[++mm].u=nn;
            ed[mm].v=j;
            ed[mm].w=c[i][j];
        }
    }
    // for(int i=5;i<=8;i++){
    //     cout<<ed[i].u<<" "<<ed[i].v<<" "<<ed[i].w<<endl;
    // }
    sort(ed+1,ed+mm+1,cmp);
    long long cnt(0ll),ans(0ll);
    for(int i=1;i<=mm;i++){
        if(find(ed[i].u)!=find(ed[i].v)){
            p[find(ed[i].v)]=find(ed[i].u);
            ans+=ed[i].w;
            if(ed[i].u>n&&!v[ed[i].u]){
                ans+=c[ed[i].u-n][0];
                v[ed[i].u]=1;
            }
            if(ed[i].v>n&&!v[ed[i].v]){
                ans+=c[ed[i].v-n][0];
                v[ed[i].v]=1;
            }
            if(!(ed[i].u>n||ed[i].v>n)){
                cnt++;
            }
            if(cnt==n-1){
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}