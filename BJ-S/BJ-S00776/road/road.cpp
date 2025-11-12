#include<bits/stdc++.h>
using namespace std;
long long city[5200][5200];
long long cost[5200];
int n,m,k;
long long bu[5200];
long long ans=LONG_MAX;
long long djk(int i){
    stack<int> q;
    q.push(1);
    cost[1]=0;
    while(!q.empty()){
        int num=q.top();
        q.pop();
        for(int i=1;i<=n+k;i++){
            if(i==num or i>n and i-n!=i) continue;
            if(city[num][i]<cost[i]){
                q.push(i);
                cost[i]=city[num][i];
            }
        }
    }
    long long sum=0;
    for(int i=1;i<=n+k;i++){
        if(cost[i]<1e9) sum+=cost[i];
    }
    return sum;
}
long long sum=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    memset(city,0x3f,sizeof(city));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        city[u][v]=city[v][u]=w;
    }
    for(int i=n+1;i<=n+k;i++){
        cin >> bu[i];
        for(int j=1;j<=n;j++){
            int w;
            scanf("%d",&w);
            city[i][j]=city[j][i]=w;
        }
    }
    memset(cost,0x3f,sizeof(cost));
    ans=djk(30);
    for(int i=1;i<=k;i++){
        long long now=-bu[i+n];
        for(int j=1;j<=n;j++){
            for(int l=j+1;l<=n;l++){
                if(city[j][n+i]+city[n+i][l]<city[j][l]){
                    now-=city[j][n+i]+city[n+i][l]-city[j][l];
                }
            }
        }
        if(now<ans) sum=max(sum,now);
    }
    cout << ans-sum;
}
