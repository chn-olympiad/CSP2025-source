#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    if (n==3){
        if (a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))ans++;
    }
    cout<<ans;
    return 0;
}
