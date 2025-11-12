#include <iostream>
#include <bits/stdc++.h>
using namespace std;
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int a[100006],b[100006];
int main()
{
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    long long ans=0;
    for (int i=3;i<=n;i++){
        for (int j=1;j<=i-1;j++){
            for (int z=j;z<=i-1;z++){
                if(b[z]-b[j-1]>a[i]){
                    ans++;
                }
            }
        }
    }
    if(n>3){
        cout << ans/2*3;
    }else{
        cout << ans;
    }

    return 0;
}
