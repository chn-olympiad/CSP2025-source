#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct e{
    long long to,w;
};
struct f{
    long long c;
    vector<e> a;
};
struct g{
    long long v,w;
    vector<bool> vis2;
};
vector<e> a[10005];
f b[15];
long long ans[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(ans,0x7f,sizeof(ans));
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e x,y;
        x.to=v;
        y.to=u;
        x.w=w;
        y.w=w;
        a[u].push_back(x);
        a[v].push_back(y);
    }
    for(int i=1;i<=k;i++){
        cin>>b[i].c;
        for(int j=1;j<=n;j++){
            e x;
            cin>>x.w;
            x.to=j;
            b[i].a.push_back(x);
        }
    }
    queue<g> q;
    vector<bool> vvv(15);
    q.push({1,0,vvv});
    while(!q.empty()){
        g eee=q.front();
        q.pop();
        if(eee.w<ans[eee.v]){
            ans[eee.v]=eee.w;
        }
        else{
            continue;
        }
        for(int i=0;i<a[eee.v].size();i++){
            e edge=a[eee.v][i];
            q.push({edge.to,eee.w+edge.w, eee.vis2});
        }
        for(int j=1;j<=k;j++){
            f fucc=b[j];
            if(eee.vis2[j]){
                continue;
            }
            for(int p=0;p<fucc.a.size();p++){
                vector<bool> newvis;
                newvis.push_back(0);
                for(int q=1;q<=k;q++){
                    newvis.push_back(q==j?1:eee.vis2[q]);
                }
                q.push({fucc.a[p].to,eee.w+(eee.vis2[j]?0:fucc.c)+fucc.a[eee.v].w+fucc.a[p].w,newvis});
            }
        }
    }
    long long water_fucc=-0x7fffffffffffffff;
    for(int i=1;i<=n;i++){
        water_fucc=max(water_fucc,ans[i]);
    }
    cout<<water_fucc;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
