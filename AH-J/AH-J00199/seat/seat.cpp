#include <bits/stdc++.h>
using namespace std;

const int N=15;
int n,m,sc[N*N],r,p;

int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>sc[i];
    r=sc[1];
    sort(sc+1,sc+n*m+1,[](int a,int b){
         return a>b;
    });
    for (int i=1;i<=m;i++) {
        if (i%2) {
            for (int j=1;j<=n;j++) {
                p++;
                if (sc[p]==r) {
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        } else {
            for (int j=n;j>=1;j--) {
                p++;
                if (sc[p]==r) {
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
