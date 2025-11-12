#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
struct P{
    int a,b,c;
};
bool cmp1(P x,P y){
    return x.a < y.a;
}
bool cmp2(P x,P y){
    return x.a-x.b < y.a-y.b;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        P a[100005];
        int n,xinga = 1,xingb = 1;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i].a >> a[i].b >> a[i].c;
            if(a[i].b != 0 || a[i].c != 0) xinga = 0;
            if(a[i].c != 0) xingb = 0;
        }
        if(xinga == 1){
            int ans = 0;
            sort(a+1,a+n+1,cmp1);
            for(int i = n; i > n/2; i--){
                ans += a[i].a;
            }
            cout << ans << "\n";
        }else if(xingb == 1){
            int ans = 0;
            sort(a+1,a+n+1,cmp2);
            for(int i = n; i > n/2; i--){
                ans += a[i].a;
            }
            for(int i = 1; i <= n/2; i++){
                ans += a[i].b;
            }
            cout << ans << "\n";
        }else{
            int ans = 0;
            for(int i = 1; i <= n; i++){
                if(a[i].c != 0){
                    ans += a[i].c;
                    a[i].a -= a[i].c;
                    a[i].b -= a[i].c;
                    a[i].c = 0;
                }
            }
            int aa = 0,bb = 0,cc = 0;
            sort(a+1,a+n+1,cmp2);
            for(int i = n; a[i].a > a[i].b; i--){
                if(a[i].a > 0 && aa < n/2) ans += a[i].a,aa++;
                else if(cc < n/2) cc++;
                else ans += a[i].b,bb++;
            }
            for(int i = 1; a[i].a <= a[i].b; i++){
                if(a[i].b > 0 && bb < n/2) ans += a[i].b,bb++;
                else if(cc < n/2) cc++;
                else ans += a[i].a,aa++;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
