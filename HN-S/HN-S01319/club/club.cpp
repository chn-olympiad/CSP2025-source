#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x, y, z, t;
    bool operator < (const node &A)const{
        return t < A.t;
    }
} a[1000010], b[1000010], c[1000010], d[1000010];
long long n, ans, cnt1, cnt2, cnt3;
void solve(){
    cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
    scanf("%lld", &n);
    for(long long i = 1; i <= n; i++){
        scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
        ans += max({a[i].x, a[i].y, a[i].z});
        a[i].t = 2 * max({a[i].x, a[i].y, a[i].z}) - a[i].x - a[i].y - a[i].z + min({a[i].x, a[i].y, a[i].z});
        if(a[i].x == max({a[i].x, a[i].y, a[i].z})) b[++cnt1] = a[i];
        if(a[i].y == max({a[i].x, a[i].y, a[i].z})) c[++cnt2] = a[i];
        if(a[i].z == max({a[i].x, a[i].y, a[i].z})) d[++cnt3] = a[i];
    }
    if(cnt1 > n/2){
        sort(b+1, b+cnt1+1);
        for(long long i = 1; cnt1-i+1>n/2; i++){
            ans -= b[i].t;
        }
    }
    if(cnt2 > n/2){
        sort(c+1, c+cnt2+1);
        for(long long i = 1; cnt2-i+1>n/2; i++){
            ans -= c[i].t;
        }
    }
    if(cnt3 > n/2){
        sort(d+1, d+cnt3+1);
        for(long long i = 1; cnt3-i+1>n/2; i++){
            ans -= d[i].t;
        }
    }
    printf("%lld\n", ans);
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    long long ______;
    scanf("%lld", &______);
    while(______--) solve();
    return 0;
}
/*
现在向下穿越 向下穿越 主人还了我自由
各位观众朋友 观众朋友 有没有将我想念
我不会再离开 因为有着 恐惧在她血里面
我要继续加害 继续加害 妄想的女孩
现在向下穿越 向下穿越 反思我犯的罪孽
需要怎么祈求 怎么祈求 才能够被谁拯救
我是罪魁祸首 失去自由 最最该死的妖怪
我是无法停止 无法停止 妄想的女孩
*/
