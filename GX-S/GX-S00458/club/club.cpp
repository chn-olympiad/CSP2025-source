#include<bits/stdc++.h>
#define ll long long
#define ci const int
#define vi vector<int>
using namespace std;
ci maxn =  1e5 + 5;



struct SS{
    ll i, j, k;
}a[maxn];
int n;
int t;

SS p1[maxn], p2[maxn], p3[maxn];

    bool cmp1(SS a, SS b){
        return a.i - max(a.j, a.k) > b.i - max(b.j, b.k);
    }
    bool cmp2(SS a, SS b){
        return a.j - max(a.i, a.k) > b.j - max(b.i, b.k);
    }

    bool cmp3(SS a, SS b){
        return a.k - max(a.j, a.i) > b.k - max(b.j, b.i);
    }


int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        ll ans = 0;
        cin >> n;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i].i >> a[i].j >> a[i].k;
            if(a[i].i > a[i].j){
                if(a[i].k > a[i].i) p3[++cnt3] = a[i], ans += a[i].k;
                else p1[++cnt1] = a[i], ans += a[i].i;
            }
            else{
                if(a[i].k > a[i].j) p3[++cnt3] = a[i], ans += a[i].k;
                else p2[++cnt2] = a[i], ans += a[i].j;
            }
        }
        if(cnt1 >= 1)
        sort(p1 + 1, p1 + cnt1 + 1, cmp1);
        if(cnt2 >= 1)
        sort(p2 + 1, p2 + cnt2 + 1, cmp2);
        if(cnt3 >= 1)
        sort(p3 + 1, p3 + cnt3 + 1, cmp3);
    //    for(int i = 1; i <= cnt1; i++){
  //          cout << p1[i].i;
//        }
        //cout << '\n';
      //  for(int i = 1; i <= cnt2; i++){
    //        cout << p2[i].j;
  //      }
//        cout << '\n';
        //for(int i = 1; i <= cnt3; i++){
      //      cout << p3[i].k;
    //    }
  //      cout << '\n';
//        cout << ans << '\n';
        while(cnt1 > n / 2){
            SS tp = p1[cnt1];
            cnt1--;
            ans -= tp.i;
            if(tp.j > tp.k) ans += tp.j;
            else ans += tp.k;
      //  cout << ans << '\n';
        }
        while(cnt2 > n / 2){
            SS tp = p2[cnt2];
            cnt2--;
            ans -= tp.j;
            if(tp.i > tp.k) ans += tp.i;
            else ans += tp.k;
        //cout << ans << '\n';
        }
        while(cnt3 > n / 2){
            SS tp = p3[cnt3];
            cnt3--;
            ans -= tp.k;
            if(tp.i > tp.j) ans += tp.i;
            else ans += tp.j;
        //cout << ans << '\n';
        }
        cout << ans << '\n';
    }
}
