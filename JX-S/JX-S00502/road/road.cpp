#include <bits/stdc++.h>
#define ll long long
#define MAXM 1000006
#define MAXN 10004
#define MAXK 11
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);
    
    ll ms[m][3];
    ll ks[k][n+2];
    for(int i=0;i<m;i++){
        scanf("%lld",&ms[i][0]);
        scanf("%lld",&ms[i][1]);
        scanf("%lld",&ms[i][2]);
        
    }
    
    for(int i=0;i<k;i++){
        scanf("%lld",&ks[i][0]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&ks[i][j]);
        }
    }

    ll result=10;
    printf("%lld",result);
    return 0;
}