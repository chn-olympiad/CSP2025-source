#include <bits/stdc++.h>
using namespace std;
int T,n,a[100005][3],mx[100005],mx2[100005],p[100005],c[3],cnt,ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if(a[i][0] == min(a[i][0],min(a[i][1],a[i][2]))) mx[i] = 1,mx2[i] = 2;
            else if(a[i][1] == min(a[i][0],min(a[i][1],a[i][2]))) mx[i] = 0,mx2[i] = 2;
            else mx[i] = 0,mx2[i] = 1;
            if(a[i][mx[i]] < a[i][mx2[i]]) swap(mx[i],mx2[i]);
        }
        c[0] = c[1] = c[2] = ans = 0;
        for(int i = 1;i <= n;i++){
            c[mx[i]]++;
            ans += a[i][mx[i]];
        }
        if(max(c[0],max(c[1],c[2])) <= n / 2) cout << ans << '\n';
        else{
            int t;
            if(c[0] == max(c[0],max(c[1],c[2]))) t = 0;
            else if(c[1] == max(c[0],max(c[1],c[2]))) t = 1;
            else t = 2;
            cnt = 0;
            for(int i = 1;i <= n;i++) if(mx[i] == t) p[++cnt] = a[i][mx[i]] - a[i][mx2[i]];
            sort(p + 1,p + cnt + 1);
            for(int i = 1;i <= c[t] - n / 2;i++) ans -= p[i];
            cout << ans << '\n';
        }
    }
    return 0;
}
