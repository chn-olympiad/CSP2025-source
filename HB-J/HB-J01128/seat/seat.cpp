#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n*m;i++)
    {
        for(int j=i;j<n*m;j++)
        {
            if(a[i]<a[j])
                swap(a[i],a[j]);
        }
    }
    int ans;
    for(int i=1;i<n*m;i++)
    {
        if(a[0]>a[i])
        {
            ans=i;
            break;
        }
    }
    if((ans/n)%2==0)
    {
        if(ans%n==0)
            cout<<ans/n<<' '<<ans%n;
        else
            cout<<ans/n+1<<' '<<ans%n;

    }
    else
    {
        if(ans%n==0)
            cout<<ans/n<<' '<<m-ans%n+1;
        else
            cout<<ans/n+1<<' '<<m-ans%n+1;
    }
    return 0;
}

