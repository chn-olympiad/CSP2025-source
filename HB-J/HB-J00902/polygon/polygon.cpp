#include <bits/stdc++.h>
using namespace std;

int n,a[5001];

int main () {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf ("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf ("%d",&a[i]);
    }
    if (a[1]<a[2]+a[3]&&a[2]<a[1]+a[3]&&a[3]<a[1]+a[2]) {
        printf ("1");
    }
    else {
        printf ("0");
    }
    return 0;
}
