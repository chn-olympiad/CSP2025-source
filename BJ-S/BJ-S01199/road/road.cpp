#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int maxn=1e4+5;
struct node{
    int u,v,w;
}e[N],e2[11*maxn],e3[maxn];
int cnt2;
int fa[maxn];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
int c[maxn];
int a[15][maxn];
bool cmp(node x,node y){
        return x.w<y.w;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(e+1,e+1+m,cmp);
    int cnt=0;
    int sum=0;
    for(int i=1;i<=m;i++){
        if(cnt==n-1)break;
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fu=find(u),fv=find(v);
        if(fu==fv){
            continue;
        }
        else{
            fa[fu]=fv;
            cnt++;
            e3[cnt]=e[i];
            sum+=w;
        }
    }
    int ans=sum;
    for(int i=1;i<(1<<k);i++){
        memset(e2,0,sizeof e2);
        int tmp=0;
        cnt2=n-1;
        for(int j=1;j<n;j++){
            e2[j]=e3[j];
        }
        for(int t=1;t<=n;t++){
            for(int j=1;j<=k;j++){
                if(((1<<(j-1))&i)!=0){
                    e2[++cnt2].w=a[j][t];
                    e2[cnt2].u=n+j;
                    e2[cnt2].v=t;
                }
            }
        }
        for(int i=1;i<=n+k;i++){
            fa[i]=i;
        }
        sort(e2+1,e2+1+cnt2,cmp);
        cnt=0;
        sum=0;
        for(int j=1;j<=k;j++){
            if(((1<<(j-1))&i)!=0){
                sum+=c[j];
                tmp++;
            }
        }
        for(int i=1;i<=cnt2;i++){
            if(cnt==n+tmp-1)break;
            int u=e2[i].u,v=e2[i].v,w=e2[i].w;
            int fu=find(u),fv=find(v);
            if(fu==fv){
                continue;
            }
            else{
                fa[fu]=fv;
                cnt++;
                sum+=w;
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
