#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int x=a[1],y,z;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++)if(a[i]==x)y=i;
    if(y%n==0)
    {
        if(y/n%2==0)cout<<"1"<<" "<<y/n;
        else cout<<n<<" "<<y/n;
    }
    else
    {
        if(y/n%2==0)cout<<n-y%n<<" "<<y/n+1;
        else cout<<y%n<<" "<<y/n+1;
    }
    return 0;
}
