#include <bits/stdc++.h>
using namespace std;

int n,m,a[101],b[101],sum=0,ans1=0,ans2=0;

int main () {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf ("%d%d",&n,&m);
    for (int i=1;i<=n*m;i++) {
        scanf ("%d",&a[i]);
        b[i]=i;
    }
    for (int i=1;i<=n*m;i++) {
        for (int j=i;j>=2;j--) {
            if (a[j]>a[j-1]) {
                swap (a[j],a[j-1]);
                swap (b[j],b[j-1]);
            }
            else {
                break;
            }
        }
    }
    for (int i=1;i<=n*m;i++) {
        if (b[i]==1) {
            sum=i;
            break;
        }
    }
    ans1=sum/n;
    if (sum%n!=0) {
        ans1++;
    }
    if (ans1%2==1) {
        ans2=sum%n;
        if (ans2==0) {
            ans2=n;
        }
    }
    else {
        ans2=n-sum%n+1;
        if (ans2==n+1) {
            ans2=1;
        }
    }
    printf ("%d %d",ans1,ans2);
    return 0;
}
