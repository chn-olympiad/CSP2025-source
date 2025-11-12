#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n;
long long ans = 0;
struct node{
    int a, b, c;
}d[N];
int Cost(const node& dm){
    int res = 0;
    if((dm.a >= dm.b) && (dm.a >= dm.c)){
        res = dm.a - max(dm.b, dm.c);
    }else if((dm.b >= dm.a) && (dm.c >= dm.a)){
        res = dm.b - max(dm.a, dm.c);
    }else{
        res = dm.c - max(dm.a, dm.b);
    }
    return res;
}
bool cmp(const node& x, const node& y){
    int Cx = Cost(x), Cy = Cost(y);
    if(Cx != Cy) return Cx > Cy;
    return max(x.a, max(x.b, x.c)) > max(y.a, max(y.b, y.c));
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> d[i].a >> d[i].b >> d[i].c;
        }
        sort(d + 1, d + n + 1, cmp);
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int i = 1; i <= n; i++){
            if(cnt1 == n / 2){
                if(d[i].b >= d[i].c){
                    ans += d[i].b;
                    cnt2++;
                }else{
                    ans += d[i].c;
                    cnt3++;
                }
            }else if(cnt2 == n / 2){
                if(d[i].a >= d[i].c){
                    ans += d[i].a;
                    cnt1++;
                }else{
                    ans += d[i].c;
                    cnt3++;
                }
            }else if(cnt3 == n / 2){
                if(d[i].a >= d[i].b){
                    ans += d[i].a;
                    cnt1++;
                }else{
                    ans += d[i].b;
                    cnt2++;
                }
            }else{
                if((d[i].a >= d[i].b) && (d[i].a >= d[i].c)){
                    ans += d[i].a;
                    cnt1++;
                }else if((d[i].b >= d[i].a) && (d[i].b >= d[i].c)){
                    ans += d[i].b;
                    cnt2++;
                }else{
                    ans += d[i].c;
                    cnt3++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
