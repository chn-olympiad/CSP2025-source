#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
inline int read(){
    int x = 0, neg = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') neg = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x<<1) + (x<<3) + c - '0';
        c = getchar();
    }
    return x * neg;
}
int n, tmp[4];
ll ans;
struct tri{
    pair<int,int> val[4];
} a[N];
bool cmp1(tri A, tri B){
    return A.val[3].first > B.val[3].first;
}
bool cmp2(tri A, tri B){
    int dA = A.val[3].first - A.val[2].first;
    int dB = B.val[3].first - B.val[2].first;
    return dA < dB;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T = read();
    while(T--){
        n = read();
        ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                a[i].val[j] = {read(), j};
            }
            sort(a[i].val + 1, a[i].val + 4);
        }
        sort(a + 1, a + n + 1, cmp1);
        int cnt[4] = {0,0,0,0};
        for(int i = 1; i <= n; i++) {
            ans += a[i].val[3].first;
            cnt[a[i].val[3].second]++;
        }
        int mx = max(cnt[1], max(cnt[2], cnt[3]));
        if(mx <= n / 2){
            printf("%lld\n", ans);
            continue;
        }
        sort(a + 1, a + n + 1, cmp2);
        for(int i = 1; i <= n; i++) {
            if(mx == cnt[3] && a[i].val[3].second == 3){
                ans -= a[i].val[3].first - a[i].val[2].first;
                cnt[3]--;
                cnt[a[i].val[2].second]++;
            }
            if(mx == cnt[2] && a[i].val[3].second == 2){
                ans -= a[i].val[3].first - a[i].val[2].first;
                cnt[2]--;
                cnt[a[i].val[2].second]++;
            }
            if(mx == cnt[1] && a[i].val[3].second == 1){
                ans -= a[i].val[3].first - a[i].val[2].first;
                cnt[1]--;
                cnt[a[i].val[2].second]++;
            }
            mx = max(cnt[1], max(cnt[2], cnt[3]));
            if(mx <= n / 2) break;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
