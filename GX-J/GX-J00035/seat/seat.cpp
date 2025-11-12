#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int q[n*m];
    cin >> q[0];
    int a1=q[0];
    for (int j=1;j<n*m;j++) {
        cin >> q[j];
    }
    for (int i=0;i<n*m-1;i++) {
        for (int j=0;j<n*m-1;j++) {
            if (q[j]<q[j+1]) {
                int t=q[j];
                q[j]=q[j+1];
                q[j+1]=t;
            }
        }
    }
    int h;
    int js;
    int l;
    for (int i=0;i<n*m;i++) {
        if (q[i]==a1) {
            js=i+1;
            l=(js/n)+1;
            if (l%2==1) {
                h=((i+1))%m;
            }
            if (l%2==0) {
                h=((m-(i+1)%m)-1)%m;
            }
        }
    }
    if (h==0)h=m;
    if (l==0)l=n;
    cout << l << " " << h;
    return 0;
}
