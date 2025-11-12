#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+10;

ll T, n, ans, k, cnt[5];

struct f1{
    ll a[5], b[5], x1;
}num[N];

void work(ll x){
    for (int i = 1; i < 3; i++){
        for (int j = i+1; j <= 3; j++){
            if (num[x].a[i]<num[x].a[j]){
                swap(num[x].a[i],num[x].a[j]);
                swap(num[x].b[i],num[x].b[j]);
            }
        }
    }
    num[x].x1 = num[x].a[1]-num[x].a[2];
    return;
}

bool cmp(f1 a1, f1 b1){
    return a1.x1>b1.x1;
}

void solve(){
    scanf("%lld",&n);
    k = n/2;
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld%lld",&num[i].a[1],&num[i].a[2],&num[i].a[3]);
        num[i].b[1] = 1;
        num[i].b[2] = 2;
        num[i].b[3] = 3;
        work(i);
    }
    ans = 0;
    cnt[1] = cnt[2] = cnt[3] = 0;
    sort(num+1,num+n+1,cmp);
    for (int i = 1; i <= n; i++){
        if (cnt[num[i].b[1]]<k){
            ans+=num[i].a[1];
            cnt[num[i].b[1]]++;
        }
        else{
            ans+=num[i].a[2];
            cnt[num[i].b[2]]++;
        }
    }
    printf("%lld\n",ans);
    return;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while (T--) solve();
    return 0;
}
