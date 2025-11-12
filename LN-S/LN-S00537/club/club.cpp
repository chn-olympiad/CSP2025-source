#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 1e5 + 5;

struct Stu{
    int m1, m2;
    int mi;
} stu[MAXN];

bool cmp(Stu a, Stu b){
    return a.m1 - a.m2 > b.m1 - b.m2;
}

int n;
int cnt[4];

int T;

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);

    cin >> T;

    while(T--){
        cnt[1] = cnt[2] = cnt[3] = 0;
        cin >> n;
        int a[4];
        int i1, i2, i3;
        for(int i = 0; i < n; i++){
            //i for rate, value in i for real departure
            cin >> a[1] >> a[2] >> a[3];
            i1 = 1, i2 = 2, i3 = 3;
            if(a[i1] < a[i2]) swap(i1, i2);
            if(a[i2] < a[i3]) swap(i2, i3);
            if(a[i1] < a[i2]) swap(i1, i2);
            stu[i].mi = i1;
            stu[i].m1 = a[i1], stu[i].m2 = a[i2];
        }
        sort(stu, stu + n, cmp);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += stu[i].m1;
            cnt[stu[i].mi]++;
            if(cnt[stu[i].mi] == n >> 1){
                int fulli = stu[i].mi;
                for(i = i + 1; i < n; i++){
                    if(stu[i].mi == fulli) ans += stu[i].m2;
                    else ans += stu[i].m1;
                }
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}