#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int u,v,w;
}edg[1000005];
bool cmp(node a, node b){
    return a.w<b.w;
}

int n;
int l[15][10005];
int fa[10005];
int fnd(int k){
    if(fa[k]==k)
        return k;
    return fa[k]=fnd(fa[k]);
}

int krsk(int m){
    int ans=0, cnt=0;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(edg+1,edg+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(fnd(edg[i].u) == fnd(edg[i].v))
            continue;
        fa[fnd(edg[i].u)] = fnd(edg[i].v);
        //cout<<edg[i].u<<' '<<edg[i].v<<' '<<edg[i].w<<endl;
        //for(int i=1;i<=n;i++) cout<<fa[i]<<' ';
        //cout<<endl;
        ans+=edg[i].w, cnt++;
        if(cnt>=n-1)
            break;
    }
    //cout<<cnt<<endl;
    return ans;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool ff2=1;
    int m,k,idx;
    int ans=0x3f3f3f3f,ans2;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>edg[i].u>>edg[i].v>>edg[i].w;
    for(int i=0;i<k;i++){
        for(int j=0;j<=n;j++)
            cin>>l[i][j];
        ff2 = ff2&&!l[i][0];
    }
    if(k==0){
        cout<<krsk(m);
        return 0;
    }
    if(ff2){
        for(int i=0;i<k;i++)
            for(int j=1;j<=n;j++) for(int e=j+1;e<=n;e++){
                edg[++m]={j,e,l[i][j]+l[i][e]};
            }
        cout<<krsk(m);
        return 0;
    }
    for(int i=0;i<(1<<k);i++){
        idx=m, ans2=0;
        for(int r=0;r<k;r++){
            if((1<<r)&i) continue;
            ans2+=l[r][0];
            for(int j=1;j<=n;j++) for(int e=j+1;e<=n;e++){
                edg[++idx]={j,e,l[r][j]+l[r][e]};
            }
        }
        ans=min(ans,krsk(idx)+ans2);
        for(int j=1;j<=idx;j++)
            cout<<edg[j].u<<' '<<edg[j].v<<' '<<edg[j].w<<endl;
        cout<<ans<<endl<<endl;
    }
    cout<<ans;
    return 0;
}
