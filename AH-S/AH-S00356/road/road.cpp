#include<bits/stdc++.h>
#include<iostream>
#define N 10001

using namespace std;

int n,m,k=0;
int i,j=0;
long minn=0;

int a[N][N]={0};
int u[N][N]={0};
int main(){

freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
fclose(stdin);
fclose(stdout);

cin>>n>>m>>k;

for(i=1;i<=m;i++){

        cin>>u[i][1]>>u[i][2]>>u[i][3];
    for(j=1;j<=k;j++){

        cin>>a[j][i];

    }
}
long coast[N]={0};

for(i=1;i<=m;i++){
    for(j=0;j<=m;j++){
        coast[j]=u[i][3]+a[j][i];
    }
}
sort(coast+0,coast+N);

std::cout<<coast[0];

return 0;
}
