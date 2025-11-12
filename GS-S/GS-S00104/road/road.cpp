#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,pd=0,cost=0;
    cin>>n>>m>>k;
    long long road[m+1][4]={0};
    long long across[n+1][2]={0};
    long long countryside[k+1][n+2]={0};
    for(long long i=1;i<=m;i++){
        cin>>road[i][1]>>road[i][2]>>road[i][3];
    }
    for(long long i=1;i<=k;i++){
        cin>>countryside[i][1];
        if(countryside[i][1]!=0)pd=1;
        for(long long j=1;j<=n;j++){
            cin>>countryside[i][j+1];
        }
    }
    for(long long i=1;i<=m;i++){
        for(long long j=1;j<=m;j++){
            if(road[j][3]<road[j-1][3]){
                for(long long h=1;h<n;h++){
                    swap(road[j][h],road[j-1][h]);
                }
            }
        }
    }
    long long gsh=0;
    for(long long i=1;i<n;i++){
            gsh=gsh+i;
    }
    if(pd==0){
        long long int real=0;
        for(long long i=1;i<=m;i++){
            if(real<gsh){
                cost+=road[i][3];
                across[road[i][1]][0]++;
                across[road[i][2]][0]++;
                across[min(road[i][2],road[i][1])][1]=road[i][3];
                real+=2;
            }
        }
        for(long long i=1;i<=k;i++){
            for(long long j=1;j<=n;j++){
                if(countryside[i][j+1]<across[j][1]){
                    cost-=across[j][1];
                    cost+=countryside[i][j+1];
                    across[j][1]=countryside[i][j];
                }
            }
        }
    }
    else{
        long long cost1;
        long long int real=0;
        for(long long i=1;i<=m;i++){
            if(real<gsh){
                cost+=road[i][3];
                across[road[i][1]][0]++;
                across[road[i][2]][0]++;
                across[min(road[i][2],road[i][1])][1]=road[i][3];
                real+=2;
            }
        }
        cost1=cost;
        for(long long i=1;i<=k;i++){
            int py=0;
            for(long long j=1;j<=n;j++){
                if(countryside[i][j+1]<across[j][1]){
                    cost-=across[j][1];
                    cost+=countryside[i][j+1];
                    across[j][1]=countryside[i][j];
                    py=1;
                }
            }
            if(py==1)cost+=countryside[i][1];
            cost=min(cost,cost1);
            cost1=cost;
        }
    }
    cout<<cost;
}
