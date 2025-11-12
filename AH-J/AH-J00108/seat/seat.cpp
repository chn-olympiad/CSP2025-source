#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],t,ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>t;
    a[1]=t;
    for(int i=2;i<=n*m;i++)cin>>a[i];
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==t)
        {
            ans=n*m-i+1;
            break;
        }
    }
    cout<<(ans+n-1)/n<<' ';
    if((ans+n-1)/n%2==1)
    {
        if(ans%n==0)cout<<n;
        else cout<<ans%n;
    }
    else
    {
        if(ans%n==0)cout<<1;
        else cout<<n-ans%n+1;
    }
    return 0;
}
