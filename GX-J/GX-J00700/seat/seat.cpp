#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001],b;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    b=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<n*m;j++)
        {
            if(a[j]<a[j+1]) swap(a[j],a[j+1]);
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==b)
        {
            b=i;
            break;
        }
    }
    if(b%n!=0)
    {
        cout<<b/n+1<<" ";
        if((b/n+1)%2==0)
        {
            cout<<n-b%n+1;
        }
        else
        {
            cout<<b%n;
        }
    }
    else
    {
        cout<<b/n<<" ";
        if((b/n)%2==0) cout<<n-b/n+1;
        else cout<<n;
    }
    return 0;
}
