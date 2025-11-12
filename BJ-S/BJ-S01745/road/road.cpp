#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int head[10100],v[10100],w[10100],nextn[10100],wk[10100],cnt,u[10100];
int vis[10100],ans;
void add(int uu,int vv,int ww) {
    v[++cnt]=vv;
    u[cnt]=uu;
    w[cnt]=ww;
    nextn[cnt]=head[uu];
    head[uu]=cnt;
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {
        int uu,vv,ww;
        cin>>uu>>vv>>ww;
        add(uu,vv,ww);
        add(vv,uu,ww);
    }
    for(int i=1;i<=k;i++) {
        cin>>wk[n+i];
        for(int j=1;j<=n;j++) {
            int ww;
            cin>>ww;
            add(n+i,j,ww);
            add(j,n+i,ww);
        }
    }
    int mi=1e9+10,minum;
    for(int i=1;i<=n+k;i++) {
        for(int j=head[i];j!=0;j=nextn[j]) {
            int ww=w[j];
            if(u[j]>n) {
                ww+=wk[u[j]];
            }
            if(v[j]>n) {
                ww+=wk[v[j]];
            }
            if(ww<mi) {
                mi=ww;
                minum=j;
            }
        }
    }
    cnt=0;
    int flag=n;
    vis[++cnt]=u[minum];
    vis[++cnt]=v[minum];
    if(vis[1]<=n) {
        flag--;
    }
    if(vis[2]<=n) {
        flag--;
    }
    ans+=mi;
    while(true) {
        int minn=1e9+10,idx;
        for(int i=1;i<=cnt;i++) {
            for(int j=head[vis[i]];j!=0;j=nextn[j]) {
                int ww=w[j];
                if(v[j]>n) {
                    ww+=wk[v[j]];
                }
                if(ww<minn) {
                    minn=ww;
                    idx=j;
                }
            }
        }
        vis[++cnt]=v[idx];
        ans+=minn;
        if(vis[cnt]<=n) {
            flag--;
        }
        if(flag==0) {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
