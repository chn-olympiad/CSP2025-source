#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[20],b[15][10005],cnt2;
int fa[20005];
int cnt;
struct node{
    int u,v,w;
}a[2000005],d[2000005];
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
    return x.w<y.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++) d[i]=a[i];
    int ans=1e18;
    for(int i=0;i<(1<<k);i++){
        cnt=m,cnt2=n;
        int s=0;
        for(int j=1;j<=m;j++) a[j]=d[j];
        for(int j=0;j<k;j++){
            if((i>>j)&1){
                cnt2++;
                s+=c[j+1];
                for(int l=1;l<=n;l++)
                a[++cnt]={cnt2,l,b[j+1][l]};
            }
        }
        sort(a+2+m,a+1+cnt,cmp);
        for(int j=1;j<=cnt2;j++) fa[j]=j;
        int l=m+1;
        for(int j=1;j<=m;j++){
            while(a[l].w<=a[j].w&&l<=cnt){
            int fx=find(a[l].u),fy=find(a[l].v);
            if(fx!=fy){
                s+=a[l].w;
                fa[fx]=fy;
            }
            l++;
            }
            int fx=find(a[j].u),fy=find(a[j].v);
            if(fx!=fy){
                s+=a[j].w;
                fa[fx]=fy;
            }
        }
        while(l<=cnt){
            int fx=find(a[l].u),fy=find(a[l].v);
            if(fx!=fy){
                s+=a[l].w;
                fa[fx]=fy;
            }
            l++;
        }
        ans=min(ans,s);
    }
    cout<<ans;
    return 0;
}
//Ren5Jie4Di4Ling5%
