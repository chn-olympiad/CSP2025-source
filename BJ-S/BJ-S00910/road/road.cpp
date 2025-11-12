#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,v,l;
}u[1000006];
int f[18],c[12][10005];
int q[10005];
int n,m,k;
bool cmp(node _,node __){
    return _.l<__.l;
}
int fin(int cp){
    if(q[cp]==cp){
        return cp;
    }
    return q[cp]=fin(q[cp]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++){
        cin>>u[i].a>>u[i].v>>u[i].l;
    }
    sort(u+1,u+m+1,cmp);
    bool flag=true;
    for(int i=1;i<=k;i++){
        cin>>f[i];
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            q[i]=i;
        }
        long long ans=0;
        for(int i=1;i<=m;i++){
            int pp=fin(u[i].a),qq=fin(u[i].v);
            if(pp!=qq){
                q[pp]=qq;
                ans+=u[i].l;
            }
        }
        cout<<ans;
    }else{
        cout<<0;
    }
    return 0;
}