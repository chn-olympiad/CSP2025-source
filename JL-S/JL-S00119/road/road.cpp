#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int u,v,w;
}e[2000005];
int a[15][100005],ans;
int n,m,k,sv[15],f[1000005];

int find(int u){
    return f[u]==u ? u : f[u]= find(f[u]);
}

bool cmp(node x,node y){
    return x.w<y.w;
}

void kruscal(int g){
    sort(e+1,e+m+1,cmp);
    int cnt=1;
    for(int i=1;i<=m;i++){
        int fu=find(e[i].u),fv=find(e[i].v);
        if(fu==fv)continue;
        f[fu]=fv;
        ans+=e[i].w;
        cnt++;
        if(cnt==g)break;
    }
    return;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    bool flag=0;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>sv[i];
        if(sv[i]!=0)flag=1;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(flag==0){
        for(int i=1;i<=n+k;i++){
            f[i]=i;
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                m++;
                e[m].w=a[i][j];
                e[m].u=n+i;
                e[m].v=j;
            }
        }
        kruscal(n+k);
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            m++;
            e[m].w=a[i][j]+sv[i];
            e[m].u=n*i+j;
            e[m].v=n*(i-1)+j;
            for(int l=1;l<=n;l++){
                if(l==j)continue;
                m++;
                e[m].w=a[i][l];
                e[m].u=n*i+j;
                e[m].v=n*(i-1)+l;
            }
        }
    }
    for(int i=1;i<=n*k+n;i++){
        f[i]=i;
    }
    for(int i=1;i<=k;i++){
        for(int j=2;j<=n;j++){
            f[i*n+j]=f[i*n+j-1];
        }
    }
    kruscal(n*(k+1));
    cout<<ans;
    return 0;
}
