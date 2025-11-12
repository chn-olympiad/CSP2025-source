#include<bits/stdc++.h>
using namespace std;
int maxx,n,a[5010],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    ans=1;
    sort(a+1,a+1+n);
    maxx=2*a[3];
    if(a[1]+a[2]+a[3]<=maxx)ans=0;
    cout<<ans<<endl;
    return 0;
}

