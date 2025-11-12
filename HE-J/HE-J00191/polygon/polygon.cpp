#include <bits/stdc++.h>
using namespace std;

int n;
int s[100010];
long long c[5010][5010];

int main(){

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for(int i=0; i<=n; i++){
        c[i][i]=1;
        c[i][0]=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%998244353;
        }
    }
    for(int i=1; i<=n; i++){
        scanf("%d", &s[i]);
    }
    long long ans=0;
    for(int i=3; i<=n; i++){
        ans+=c[n][i];
        ans%=998244353;
    }
    printf("%d\n", ans);

    return 0;

}
