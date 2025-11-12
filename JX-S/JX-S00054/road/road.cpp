#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,M=2e5+10,inf=1e18;
int n,nn,m,mm,k,c[20],a[20][M],ans=inf,fa[N],fla;
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
struct node{
    int u,v,w;
}x[N],y[N];
bool cmp(node a,node b){
    return a.w<b.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x[i].u>>x[i].v>>x[i].w;
        y[i]=x[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i])fla=1;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(fla==0){
        ans=0;
        int nn=n,mm=m;
        for(int i=1;i<=k;i++){
            nn++;
            for(int j=1;j<=n;j++){
                x[++mm].u=nn;
                x[mm].v=j;
                x[mm].w=a[i][j];
            }
        }
        for(int i=1;i<=nn;i++)fa[i]=i;
        sort(x+1,x+1+mm,cmp);
        int jjsq=0;
        for(int i=1;i<=mm;i++){
            if(find(x[i].u)==find(x[i].v))continue;
            ans+=x[i].w;
            fa[find(x[i].u)]=find(x[i].v);
            jjsq++;
            if(jjsq==nn-1)break;
        }
        cout<<ans;
        return 0;
    }
    for(int ii=0;ii<(1ll<<k);ii++){
        int num=0,nn=n,mm=m;
        for(int i=1;i<=m;i++){
            x[i]=y[i];
        }
        for(int j=0;j<k;j++){
            if((1ll<<j)&ii){
                num+=c[j+1];
                nn++;
                for(int o=1;o<=n;o++){
                    x[++mm].u=nn;
                    x[mm].v=o;
                    x[mm].w=a[j+1][o];
                }
            }
        }
        for(int i=1;i<=nn;i++)fa[i]=i;
        sort(x+1,x+1+mm,cmp);
        int jjsq=0;
        for(int i=1;i<=mm;i++){
            if(find(x[i].u)==find(x[i].v))continue;
            num+=x[i].w;
            if(num>ans)break;
            fa[find(x[i].u)]=find(x[i].v);
            jjsq++;
            if(jjsq==nn-1)break;
        }
        ans=min(ans,num);
    }
    cout<<ans;
    return 0;
}
