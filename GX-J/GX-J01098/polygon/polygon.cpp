#include <bits/stdc++.h>
using namespace std;
int n,a[5005],s=0;
main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]+a[j]>a[j]*2){
                s++;
            }
        }
    }
    cout<<s%998244353;
    return 0;
}
