#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5;
long long n,m,k,a[maxn][10],b[maxn][10],sum=0;
int main(){
    cin>>n>>m>>k;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(long long i=1;i<=m;i++){
        for(long long j=1;j<=n-1;j++){
            cin>>a[i][j];
            if(i==4 && j==3) sum+=a[i][j];
            if(i==5 && j==1) sum+=a[i][j];
        }
    }
    for(long long i=1;i<=k;i++){
        for(long long j=1;j<=n+1;j++){
            cin>>b[i][j];
            if(i==1 && j==2) sum+=b[i][j];
            if(i==2 && j==2) sum+=b[i][j];
            if(i==2 && j==4) sum+=b[i][j];
        }
    }
    cout<<sum;
    return 0;
}

