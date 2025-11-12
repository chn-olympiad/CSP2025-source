#include <bits/stdc++.h>
using namespace std;
int n,a[5010],sum=0;
int main () {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    if(sum>a[n]*2)printf("1\n");
    else printf("0\n");
    return 0;
}