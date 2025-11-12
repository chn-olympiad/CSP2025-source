#include <iostream>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define ll long
using namespace std;
ll now_money;
ll n,m,k,road[10001][10001]={1000001},u,v,w,c[10001][10001]={0},i,j;
ll sum_money=0,cheap_city=1000001,min_money=1000001,sum_city=0,more_money[10001]={0};

//void dfs(ll town,ll city_f,ll city_s){
//    if(city_s>n)return;
//
//    if(road[city_f][city_s]>=c[town][city_s]+c[town][city_f]){
//        cheap_city=min(cheap_city,c[town][city_f]);
//        cheap_city=min(cheap_city,c[town][city_s]);
//        now_money+=c[town][j];
//        sum_city++;
//        if(now_money+cheap_city+c[town][0]<=road[city_f][city_s]&&now_money+cheap_city+c[town][0]<=min_money){
//            min_money=now_money+cheap_city+c[town][0];
//            more_money[town]=cheap_city;
//            road[city_f][city_s]=1000001;
//            road[city_s][city_f]=1000001;
//        }
//
//    }
//    dfs(town,city_f,city_s+1);
//
//}


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(i=1;i<=m;i++){
        cin>>u>>v>>w;
        road[u][v]=w;
        road[v][u]=w;
        if(k==1)sum_money+=w;
    }
 //   for(i=1;i<=k;i++){
 //       for(j=0;j<=n;j++){
 //           cin>>c[i][j];
 //           c[j][i]=c[i][j];
 //       }
 //   }
 //   for(i=1;i<=n;i++){
 //       for(j=1;i<=k;j++){
 //           cheap_city=1000001,sum_city=0;
 //           dfs(j,i,i+1);
 //       }
 //   }
 //   for(i=1;i<=n;i++){
 //       for(j=i+1;j<=n;j++){
 //           if(road[i][j]!=1000001){
 //               sum_money+=road[i][j];
 //           }
 //       }
 //       sum_money+=more_money[i];
 //   }


    cout<<sum_money;
    return 0;
}
