#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int q=a[1],w=0;
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i+1;j<=n*m;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==q)
        {
            w=i;
        }
    }
    if(w%n==0)
    {
        if((w/n)%2==0)
        {
            cout<<w/n<<' '<<1;
            return 0;
        }
        else if((w/n)%2==1)
        {
            cout<<w/n<<' '<<n;
            return 0;
        }
    }
    else if(w%n!=0)
    {
        if((w/n+1)%2==0)
        {
            cout<<w/n+1<<' '<<n-(w%n)+1;
            return 0;
        }
        else if((w/n+1)%2==1)
        {
            cout<<w/n+1<<' '<<w%n;
            return 0;
        }
    }
    return 0;
}
