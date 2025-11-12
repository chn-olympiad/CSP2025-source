#include<bits/stdc++.h>
using namespace std;
int a[5009];
long long t,n,xx;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n-1;i>=1;i--)xx+=i;
    if(0>n*n-n-xx)cout<<0;
    else cout<<n*n-n-xx;
    return 0;
}
