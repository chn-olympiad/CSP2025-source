#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll N = 1e5+5;
ll read(){
    ll a = 1,ans = 0;
    char x = getchar();
    while(x < '0'||x > '9'){if(x=='-')a=-1;x=getchar();}
    while(x >= '0'&&x <= '9')ans = ans*10+x-'0',x = getchar();
    return ans*a;
}
ll a[N][3];
ll cnt[3];
priority_queue<ll> q[3];
void work(){
    ll n = read();
    ll ans = 0;
    for(int i = 0;i < 3;i ++)while(q[i].size())q[i].pop();
    for(int i = 1;i <= n;i ++){
        a[i][0] = read(),a[i][1] = read(),a[i][2] = read();
        ll mn = min(a[i][0],min(a[i][1],a[i][2]));
        ll mx = max(a[i][0],max(a[i][1],a[i][2]));
        ll sum = a[i][0] + a[i][1] + a[i][2];
        ans += mx;
        for(int j = 0;j < 3;j ++){
            if(a[i][j] == mx)q[j].push(-mx*2 + sum - mn);
        }
    }
    for(int i = 0;i < 3;i ++){
        while(q[i].size() > n/2){
            ans += q[i].top();
            q[i].pop();
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll T = read();
    while(T--)work();
    return 0;
}
