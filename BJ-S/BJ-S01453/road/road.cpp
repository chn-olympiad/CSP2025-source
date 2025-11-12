#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxp=1e4+15;
const int maxm=2e6+5;
int n,m,k,u,v,frm[maxp],frm2[maxp],out[maxp];
ll w,ans,p,f[maxp];
bool used[maxp];
struct R {
    ll nd;
    int to;
};
vector<R>r[maxm];
queue<int>q;
void dj() {
    q.push(1);
    f[0]=f[1]=0;
    while (!q.empty()) {
        int j=q.front();
        //cout<<j<<":\n";
        q.pop();
        for (int i=0;i<r[j].size();i++) {
            v=r[j][i].to,w=r[j][i].nd;
            //cout<<v<<","<<j<<"\n";
            if (w+f[j]<f[v]&&w<f[v]-f[frm[v]]) {
                //cout<<v<<"\n";
                q.push(v);
                f[v]=f[j]+w;
                out[frm[v]]--;
                frm[v]=j;
                //cout<<v<<":"<<j<<"\n";
                out[j]++;
            }
        }
    }
    return ;
}
void fans() {
    for (int i=1;i<=n;i++)
        if (out[i]==0)
            q.push(i);
    while (!q.empty()) {
        int nw=q.front();
        q.pop();
        //cout<<nw<<":"<<f[nw]<<","<<frm[nw]<<":"<<f[frm[nw]]<<"\n";
        ans+=f[nw]-f[frm[nw]];
        if (!used[frm[nw]]) {
            used[frm[nw]]=true;
            q.push(frm[nw]);
        }
    }
    return ;
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(f,0x7f,sizeof(f));
    scanf("%d %d %d",&n,&m,&k);
    for (int i=1;i<=m;i++) {
        scanf("%d %d %lld",&u,&v,&w);
        R nw;
        nw.to=v,nw.nd=w;
        r[u].push_back(nw);
        nw.to=u;
        r[v].push_back(nw);
    }
    for (int i=1;i<=k;i++) {
        scanf("%lld",&p);
        for (int j=1;j<=n;j++) {
            scanf("%lld",&w);
            R nw;
            nw.to=j,nw.nd=w;
            r[n+i].push_back(nw);
            nw.to=n+i,nw.nd+=p;
            r[j].push_back(nw);
        }
    }
    dj();
    fans();
    cout<<ans;
    return 0;
}
