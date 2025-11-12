#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
longlong n,m,k,road[1000000][3],city[10][10001],ans=0,num=0;
cin>>n>>m>>k;
for(int i=0;i<=n;i++){
for(int j=0;j<=3;j++){
road[i][j];
}
}
for(int i=0;i<=k;i++){
for(int j=0;j<=n+1;j++){
city[i][j];
}
}
for(int i=0;i<=n;i++){
for(int j=0;j<=k;j++){
if(road[i][2]<city[j][1]+city[j][road[i][0]]+city[j][road[i][1]]){
num=road[i][2];
}else{
num=city[j][1]+city[j][road[i][0]]+city[j][road[i][1]];
}
}

ans+=num;
}
cout<<ans;
return 0;
}


