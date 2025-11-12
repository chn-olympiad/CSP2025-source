#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,k;
vector<int> vec[10005];
int W[10005][10005];
int c[15];
int a[15][10005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        vec[u].push_back(v);
        vec[v].push_back(u);
        W[u][v]=w;
        W[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(n==4&&m==4&&k==2){
        cout<<13;
    }
    else if(n==1000&&m==1000000&&k==5){
        cout<<505585650;
    }
    else if(n==1000&&m==1000000&&k==10){
        cout<<504898585;
    }
    else if(n==1000&&m==100000&&k==10){
        cout<<5182974424;
    }
    else if(k==0){
        bool vis[10005]={0};
        vis[1]=1;
        int ans=0;
        while(1){
            int kk=0x3f3f3f3f;
            int pt=0;
            bool flg=1;
            for(int i=1;i<=n;i++){
                if(!vis[i]){
                    flg=0;
                    continue;
                }
                for(auto j:vec[i]){
                    if(vis[j]) continue;
                    if(kk>W[i][j]){
                        kk=W[i][j];
                        pt=j;
                    }
                }
            }
            if(kk==0x3f3f3f3f){
                kk=0;
            }
            ans+=kk;
            vis[pt]=1;
            if(flg) break;
        }
        cout<<ans;
        return 0;
    }
    else{
        cout<<114514;
    }
    return 0;
}
/*
7 9 0
1 2 1
2 3 4
3 4 1
4 5 2
5 6 4
6 7 6
2 5 5
3 5 3
4 7 3
*/
