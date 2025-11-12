#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
        cin>>a[i];
    int tar=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    int nx=1,ny=1,dir=1;
    for (int i=1;i<=n*m;i++) {
        if (a[i]==tar) {
            cout<<ny<<" "<<nx;
            break;
        }
        if (dir==1) {
            nx++;
            if (nx>n) nx--,ny++,dir=2;
        }
        else if (dir==2) {
            nx--;
            if (nx<1) nx++,ny++,dir=1;
        }
    }
    return 0;
}
