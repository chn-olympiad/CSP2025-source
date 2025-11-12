/*#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e4+10;
const int maxm=2500010;
int n,m,k,ans,sum=1e18;
int fa[maxn],c[maxn],w[11][maxn];
struct NODE{
    int x,y,z;
} a[maxm],b[maxm];
int cnt,cnt2;
bool cmp(NODE l,NODE r){
    return l.z<r.z;
}
int find(int x){
    return (fa[x]==x?x:fa[x]=find(fa[x]));
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[++cnt]={u,v,w};
        a[++cnt]={v,u,w};
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        int u=a[i].x,v=a[i].y,w=a[i].z;
        if(find(u)==find(v)){
            continue;
        }
        fa[find(u)]=find(v);
        b[++cnt2]=a[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>w[i][j];
        }
    }
    for(int s=0;s<(1<<k);s++){
        for(int i=1;i<=n+n;i++) fa[i]=i;
        ans=0;
        cnt=0;
        for(int i=1;i<=k;i++){
            if(s&(1<<(i-1))){
                ans+=c[i];
                for(int j=1;j<=n;j++){
                    a[++cnt]={i+n,j,w[i][j]};
                    a[++cnt]={j,i+n,w[i][j]};
                }
            }
        }
        for(int i=1;i<=cnt2;i++) a[++cnt]=b[i];
        sort(a+1,a+cnt+1,cmp);
        //cout<<"#\n";
        for(int i=1;i<=cnt;i++){
            int u=a[i].x,v=a[i].y,w=a[i].z;
            if(find(u)==find(v)){
                continue;
            }
            fa[find(u)]=find(v);
            //cout<<u<<" "<<v<<" "<<w<<"\n";
            ans+=w;
        }
        //cout<<"#\n";
        //cout<<s<<" "<<ans<<'\n';
        sum=min(sum,ans);
    }
    cout<<sum<<'\n';
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
const int maxm=2e6+10;
int n,m,k,ans,sum=1e18;
int fa[maxn],c[maxn];
struct NODE{
    int x,y,z;
} a[maxm],a1[maxn],b[maxn],w[11][maxn];
int cnt,cnt2;
bool cmp(NODE l,NODE r){
    return l.z<r.z;
}
int find(int x){
    return (fa[x]==x?x:fa[x]=find(fa[x]));
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[++cnt]={u,v,w};
        a[++cnt]={v,u,w};
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        int u=a[i].x,v=a[i].y,w=a[i].z;
        a[i].x=a[i].y=a[i].z=0;
        if(find(u)==find(v)){
            continue;
        }
        fa[find(u)]=find(v);
        //cout<<u<<v<<w<<'\n';
        b[++cnt2]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            w[i][j]={i+n,j,x};
            w[i][j+n]={j,i+n,x};
        }
        sort(w[i]+1,w[i]+n+n+1,cmp);
    }
    for(int s=0;s<(1<<k);s++){
        for(int i=1;i<=n+n;i++) fa[i]=i;
        ans=0;
        cnt=0;
        for(int i=1;i<=k;i++){
            if(s&(1<<(i-1))){
                ans+=c[i];
                int j=1,p=cnt;
                for(int u=1;u<=cnt;u++){
                    a1[u]=a[u];
                }
                cnt=0;
                for(int u=1;u<=p;u++){
                    while(j<=n&&w[i][j].z<a1[u].z) a[++cnt]=w[i][j],j++;
                    a[++cnt]=a1[u];
                }
                for(j;j<=n;j++) a[++cnt]=w[i][j];
                /*for(int j=1;j<=n;j++){
                    a[++cnt]={i+n,j,w[i][j]};
                    a[++cnt]={j,i+n,w[i][j]};
                }*/
            }
        }
        int j=1,p=cnt;
        for(int i=1;i<=cnt;i++){
            a1[i]=a[i];
        }
        cnt=0;
        for(int i=1;i<=p;i++){
            while(j<=cnt2&&b[j].z<a1[i].z) a[++cnt]=b[j],j++;
            a[++cnt]=a1[i];
        }
        for(j;j<=cnt2;j++){
            a[++cnt]=b[j];
            //cout<<j<<'\n';
        }
        //for(int i=1;i<=cnt2;i++) a[++cnt]=b[i];
        //sort(a+1,a+cnt+1,cmp);
        //cout<<"#\n";
        for(int i=1;i<=cnt;i++){
            int u=a[i].x,v=a[i].y,w=a[i].z;
            a[i].x=a[i].y=a[i].z=0;
            if(find(u)==find(v)){
                continue;
            }
            fa[find(u)]=find(v);
            //cout<<u<<" "<<v<<" "<<w<<"\n";
            ans+=w;
        }
        //cout<<"#\n";
        //cout<<s<<" "<<ans<<'\n';
        sum=min(sum,ans);
    }
    cout<<sum<<'\n';
    return 0;
}
