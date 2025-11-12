#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510;
ll n,m,INF = 998244353,c[N],p[N];
ll P(ll a,ll b){
    ll cnt = 1;
    for(ll i = b;i > b-a;i--){
        cnt = cnt * i % INF;
    }
    return cnt;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> p[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> c[i];
    }
    if(p[10] or m == 1){
        cout << P(n,n);
    }

    return 0;
}
