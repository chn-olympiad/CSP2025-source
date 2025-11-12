#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long s;
int main(){
    freopen(polygon.in,"r",stdin);
    freopen(polygon.out,"w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n-2;i>=1;i--){
        s=s+(n-i-1)*i;
        s=s%998244353;
    }
    cout<<s%998244353;

    return 0;
}
