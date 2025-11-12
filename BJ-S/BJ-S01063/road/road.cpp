#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
int al,ak,aj;
struct node{
    int u,v,w;
};
node e[1100005];
int q[15];
int b[15][10005];
int f[10010];
int pl=0;
ll ans=0;
bool cmp(node a,node b){
    return a.w<b.w;
}
int findd(int x){
    if(f[x]==x) return x;
    return f[x]=findd(f[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>al>>ak>>aj;
        e[++pl]={al,ak,aj};
    }
    for(int i=1;i<=k;i++){
        cin>>q[i];
        int flag=0;
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
            if(b[i][j]==0){
                flag=j;
            }
        }
        for(int j=1;j<=n;j++){
            if(flag==j){
                continue;
            }
            e[++pl]={flag,j,b[i][j]};
        }
    }
    sort(e+1,e+pl+1,cmp);
    for(int i=1;i<=pl;i++){
        int fa=findd(e[i].u);
        int fb=findd(e[i].v);
        if(fa==fb){
            continue;
        }
        ans+=e[i].w;
        f[fa]=fb;
    }
    cout<<ans;
    return 0;
}
