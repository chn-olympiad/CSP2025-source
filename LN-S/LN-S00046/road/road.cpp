#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int ans;
bool flag;
struct edge{
    int st;
    int en;
    int lon;
};
bool cmp(edge a,edge b){
    return a.lon<b.lon;
}
edge ed[1000010];
int c;
bool vis[10010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>ed[i].st>>ed[i].en>>ed[i].lon;
    for(int i=1;i<=k;i++){
        cin>>c>>a;
        if(c!=0&&a!=0)flag=1;
    }
    if(flag==0&&k>0)cout<<0;
    else{
    sort(ed+1,ed+m+1,cmp);
    for(int i=1,int num=0;i<=m&&num<n-1;i++){
        if(vis[ed[i].st]==0||vis[ed[i].en]==0){
            ans+=ed[i].lon;
            vis[ed[i].st]=1;
            vis[ed[i].en]=1;
            num++;
        }
    }
    cout<<ans;
    }
    return 0;
}
