#include <bits/stdc++.h>
using namespace std;
#define int long long
struct sub{
    int b, d;
};
struct s{
    int bi, da;
}x[5][100005];
struct stu{
    sub a1, a2, a3, m1, m2, m3;
}a[1000005];
bool cmp1(sub x, sub y){
    return x.d < y.d;
}
bool cmp2(s x, s y){
    return x.da < y.da;
}
int n;
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int q;
    cin >> q;
    while(q--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i].a1.d >> a[i].a2.d >> a[i].a3.d;
            a[i].a1.b = 1, a[i].a2.b = 2, a[i].a3.b = 3;
            a[i].m1 = max(a[i].a1, max(a[i].a2, a[i].a3, cmp1), cmp1);
            a[i].m3 = min(a[i].a1, min(a[i].a2, a[i].a3, cmp1), cmp1);
            a[i].m2.b = 6 - a[i].m1.b - a[i].m3.b;
            a[i].m2.d = a[i].a1.d + a[i].a2.d + a[i].a3.d - a[i].m1.d - a[i].m3.d;
        }
        int cnt[5], maxn;
        for(int i = 1; i <= n; i++){
            cnt[a[i].m1.b] ++;
            x[a[i].m1.b][cnt[a[i].m1.b]].da = a[i].m1.d;
            x[a[i].m1.b][cnt[a[i].m1.b]].bi = i;
        }
        maxn = max(cnt[1], max(cnt[2], cnt[3]));
        int sum = 0;
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= cnt[i]; j++){
                sum = sum + x[i][j].da;
            }
        }
        if(maxn <= n / 2){
            cout << sum << "\n";
        }else{
            int t;
            if(cnt[1] == maxn) t = 1;
            else if(cnt[2] == maxn) t = 2;
            else if(cnt[3] == maxn) t = 3;
            s y[100005];
            for(int i = 1; i <= cnt[t]; i++){
                y[i].da = x[t][i].da - a[x[t][i].bi].m2.d;
                y[i].bi = x[t][i].bi;
            }

            sort(y + 1, y + cnt[t] + 1, cmp2);
            for(int i = 1; i <= cnt[t] - n / 2; i++){
                sum -= y[i].da;
            }
            cout << sum << "\n";
        }
        for(int i = 1; i <= 3; i++) cnt[i] = 0;
    }
    return 0;
}