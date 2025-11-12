//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int map1[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            map1[i][j]=99999999;
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map1[u][v]=w;map1[v][u]=w;
        //map1[u][0]=min(map1[u][0],map[u][v]);map1[v][0]=min(map1[v][0],map[u][v]);
    }
    for(int i=1;i<=k;i++){
        int c;
        cin>>c;
        int villageroad[n+1];
        for(int j=1;j<=n;j++){

            cin>>villageroad[j];
        }
        for(int x=1;x<n;x++){
            for(int y=x;y<=n;y++){
                map1[x][y]=min(map1[x][y],villageroad[x]+villageroad[y]+c);
                map1[y][x]=map1[x][y];
            }
        }

    }
    int ans=0;

    vector<int> vis;
    vis.push_back(1);
    /*for(int i=2;i<=n;i++){
            int sum=99999999,t;
        for(int j=1;j<=vis.size()-1;j++){
            if(a[i][vis[j]]<=sum){
                t=j;
                sum=a[i][vis[j]];
            }
            t++;
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(sum>map1[i][j]){
                sum=map1[i][j];
                t=j;
            }
        }
        ans+=sum;
        map1[i][t]=99999999;
        map1[t][i]=99999999;
        sum=99999999
    }*/
    queue<int> q;
    q.push(1);
    vis[1]=1;
    int t=1;
    int ansans=99999999;
    for(int u=1;u<=n;u++){
        while(t<n){
            int sum=99999999,x=0;
            for(int i=1;i<=n;i++){
                if(map1[q.front()][i]<sum&&!vis[i]){
                    sum=map1[q.front()][i];
                    x=i;
                }
            }
            q.pop();
            q.push(x);
            vis[x]=1;
            t++;
            ans+=sum;

        }
        ansans=min(ans,ansans);
    }


    cout<<ansans;
}
