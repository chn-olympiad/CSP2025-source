#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b) {return a>b;}
int n,m,a[105];
signed main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1; i<=n*m; i++) cin >> a[i];
    int pos = a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1; i<=n*m; i++) {
        if(pos == a[i]) {
            pos = i;
            break;
        }
    }
    int ans1,ans2;
    if(pos % n == 0) ans1 = pos/n;
    else ans1 = (pos/n) + 1;

    if(ans1 % 2 == 1) {
        ans2 = pos%n;
        if(ans2 == 0) ans2 = n;
    }
    else ans2 = n-(pos%n)+1;

    cout << ans1 << " " << ans2;
    return 0;
}
