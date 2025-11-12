#include<bits/stdc++.h>
using namespace std;
int n;
int f[10005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    sort(a+1,a+n+1);

    return 0;
}
