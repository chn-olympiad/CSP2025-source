#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    long long ans,a[5005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=3;i<=n;i++){
        if((i=3&&a[i]+a[i+1])>=a[i+2]) ans++;
    }
    cout<<ans;
    return 0;
}
