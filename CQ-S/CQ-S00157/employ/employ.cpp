#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,m;
char s[510];
int d1[510],d2[510];
int x;
long long ans;
int dm[510];
long long C(int x,int m){
    long long res = 1;
    for(int i = 1;i<=m;i++){
        res = (res%MOD)*(x%MOD)%MOD;
        x--;
    }
    return res%MOD;
}
int p;
int main() {
    freopen("employ.in","r",stdin);
    freopen("empty.out","w",stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s+ 1);
    for(int i = 1;i<=n;i++){
        if(s[i]=='0') d2[i]++;
        else d1[i]++;
        d2[i]+=d2[i-1];
        d1[i]+=d1[i-1];
    }
    for(int i = 1;i <=n;i++){
        scanf("%d", &x);
        for(int j = 1;j<=n;j++)if(d2[j]<=x&&s[j]=='1')dm[j]++;
    }
    for(int i =1;i<=n;i++){
        if(d1[i]>=m && dm[i]>=m){
            p = min(dm[i]-m,d1[i]);
            for(int j =0;j<=p;j++){
                ans=(ans%MOD+C(dm[i],j+m)%MOD)%MOD;
            }
        }
    }
    printf("%lld", ans%MOD);
    return 0;
}
