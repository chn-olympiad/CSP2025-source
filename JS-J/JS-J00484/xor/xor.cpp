#include <iostream>
#include <bits/stdc++.h>
using namespace std;
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int a[10006];
int main()
{
    int n,k,ans=0,h=0;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        h+=a[i];
        if(a[i]==k || h==k*2 ||h==k){
            ans++;
            h=0;
        }
    }
    cout << ans;
    return 0;
}
