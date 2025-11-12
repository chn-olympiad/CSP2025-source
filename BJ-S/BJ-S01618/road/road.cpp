/*
Ren5Jie4Di4Ling5%
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[10][10005];
int road[10005][10005];
int sum=INT_MAX,acsum;
int vis[10005];
int floyed[10005][10005];

int ans[100005];
int ansi;
void dfs(int nxt){
    if(nxt==n){
        sum=min(sum,acsum);
        //for(int i=0;i<ansi;i++){
            //cout<<ans[i]<<" ";
        //}
        //cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==nxt||road[nxt][i]==-1||vis[i]==1){
            continue;
        }
        int countrycmin=INT_MAX,idx=0;
        for(int j=0;j<k;j++){
            if(countrycmin>c[j][0]+c[j][i]){
                idx=j;
                countrycmin=min(countrycmin,c[j][0]+c[j][i]);
            }
        }
        int flag=0;
        if(road[nxt][i]>countrycmin){
            //ans[ansi++]=countrycmin;
            acsum+=countrycmin;
            flag=1;
        }else{
            //ans[ansi++]=road[nxt][i];
            vis[i]=1;
            acsum+=road[nxt][i];
        }
        dfs(nxt+1);
        vis[i]=0;
        //ansi--;
        acsum-=(flag==1?countrycmin:road[nxt][i]);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    memset(road,-1,sizeof(road));
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        road[u][v]=road[v][u]=w;
    }
    int iscountryallzero=1;
    for(int i=0;i<k;i++){
        cin>>c[i][0];
        if(c[i][0]!=0){
            iscountryallzero=0;
        }
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
            if(c[i][j]!=0){
                iscountryallzero=0;
            }
        }
        if(iscountryallzero==1&&k!=0){
            cout<<0<<endl;
            return 0;
        }
    }
    if(m==n*(n-1)/2){
        int ans[100005]={};
        int ansi=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(road[i][j]!=-1&&i!=j){
                    ans[ansi++]=road[i][j];
                }
            }
        }
        sort(ans,ans+ansi);
        int ac=0;
        for(int i=0;i<n-1;i++){
            ac+=ans[i];
        }
        cout<<ac<<endl;
        return 0;
    }
    dfs(1);
    cout<<sum+1<<endl;
    return 0;
}
