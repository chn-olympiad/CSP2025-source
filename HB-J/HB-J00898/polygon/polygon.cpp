#include <bits/stdc++.h>
using namespace std;
long long a[10005],n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(a[1]+a[2]<=a[n]||a[n]+a[n-1]<=a[1]||a[n]+a[1]<=a[n-1]){
        cout<<0;
        return 0;
    }
    cout<<1;
    return 0;
}
