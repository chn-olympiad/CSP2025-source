#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>f[i];
    int cnt=0;
    for(int i=0;i<n-1;i++){
        cnt+=a[i];
    }
    cout<<cnt-1;
    return 0;
}
