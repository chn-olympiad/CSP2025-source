#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node3{
    ll v1,v2,v3,v;
} dp[N][3];
ll t,n,lim,a[N],b[N],c[N];
node3 now,ans;
node3 maxx(node3 a,node3 b){
    if(a.v > b.v) return a;
    else return b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i = 1;i <= n;i++){
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
            //cout << "!!!" << a[i].v1.v << ' ' << a[i].v2.v << ' ' << a[i].v3.v << endl;
        }
        lim = n/2;
        dp[0][0] = dp[0][1] = dp[0][2] = {0,0,0,0};
        for(int i = 1;i <= n;i++){
            now = maxx(dp[i-1][0],maxx(dp[i-1][1],dp[i-1][2]));
            if(now.v1 < lim){
                dp[i][0] = {now.v1+1,now.v2,now.v3,now.v+a[i]};
                //cout << i << " " << a[i].v1.s << endl;
            }
            else dp[i][0] = now;
            if(now.v2 < lim){
                dp[i][1] = {now.v1,now.v2+1,now.v3,now.v+b[i]};
                //cout << i << " " << a[i].v2.s << endl;
            }
            else dp[i][1] = now;
            if(now.v3 < lim){
                dp[i][2] = {now.v1,now.v2,now.v3+1,now.v+c[i]};
                //cout << i << " " << a[i].v2.s << endl;
            }
            else dp[i][2] = now;
        }
        ans = maxx(dp[n][0],maxx(dp[n][1],dp[n][2]));
        printf("%lld\n",ans.v);
    }
    return 0;
}
