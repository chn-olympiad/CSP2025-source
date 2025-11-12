#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,t,k,targ;
long long a[N][5];
int b[5];
struct T{
    long long x,pos;
}d[N];
long long ans = 0;
bool cmp(T u,T v){
    if(u.pos != targ || v.pos != targ){
        return (u.pos == targ);
    }
    return (u.x < v.x);
}
void solve(int x){
    sort(d + 1,d + n + 1,cmp);
    for(int i = 1;i <= x - k;i++){
        ans -= d[i].x;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        k = n / 2;
        long long maxa,seca,pos;
        ans = 0;
        memset(b,0,sizeof b);
        for(int i = 1;i <= n;i++) {
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            maxa = seca = -1;
            pos = 0;
            for(int j = 1;j <= 3;j++){
                if(maxa < a[i][j]){seca = max(seca,maxa);maxa = a[i][j];pos = j;}
                else seca = max(seca,a[i][j]);
            }
            ans += maxa;
            d[i].x = maxa - seca;
            d[i].pos = pos;
            b[pos]++;
        }
        for(int i = 1;i <= 3;i++){
            if(b[i] > k){
                targ = i;
                solve(b[i]);
                break;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}
