#include <bits/stdc++.h>
using namespace std;

int n,k,a[500001],s[500001],b1[5000001],b2[5000001],m=0,ans=0,sum=0;

int main () {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf ("%d%d",&n,&k);
    for (int i=1;i<=n;i++) {
        scanf ("%d",&a[i]);
    }
    for (int i=1;i<=n;i++) {
        s[i]=s[i-1]^a[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            if ((s[i]^s[j-1])==k) {
                m++;
                b1[m]=j;
                b2[m]=i;
            }
        }
    }
    for (int i=1;i<=m;i++) {
        if (b1[i]>sum) {
            ans++;
            sum=b2[i];
        }
    }
    printf ("%d",ans);
    return 0;
}
