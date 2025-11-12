#include<bits/stdc++.h>
using namespace std;
long long n, a[100005][5], cnt[5], pl[5], t;
pair<long long, long long> p[100005];
long long solve(){
    if(cnt[1] > n / 2) pl[1] = 1, pl[2] = 2, pl[3] = 3;
    if(cnt[2] > n / 2) pl[1] = 2, pl[2] = 1, pl[3] = 3;
    if(cnt[3] > n / 2) pl[1] = 3, pl[2] = 1, pl[3] = 2;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        p[i] = {max(a[i][pl[2]] - a[i][pl[1]], a[i][pl[3]] - a[i][pl[1]]), i};
        //printf("%lld %lld\n", p[i].first, p[i].second);
        ans += a[i][pl[1]];
    } sort(p + 1, p + 1 + n);
    for(int i = n / 2 + 1; i <= n; i++) ans += p[i].first;
    //printf("%lld\n", ans);
    return ans;
}int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%lld", &t);
    while(t--){
        long long ans = 0; memset(cnt, 0, sizeof(cnt));
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++){
            scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
            long long mx = max(a[i][1], max(a[i][2], a[i][3])); ans += mx;
            if(mx == a[i][1]) cnt[1]++;
            else if(mx == a[i][2]) cnt[2]++;
            else if(mx == a[i][3]) cnt[3]++;
        }if(cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) printf("%lld\n", ans);
        else printf("%lld\n", solve());
    } return 0;
}
