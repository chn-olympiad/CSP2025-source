#include<bits/stdc++.h>
using namespace std;
int mx,n,a[5050],ad;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mx=max(a[i],mx);
        ad+=a[i];
    }
    if(ad>2*mx) printf("1");
    else if(ad<=2*mx) printf("0");
    return 0;
}
