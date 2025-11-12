#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,s=0,b=0,c=0;
    cin>>n>>m;
    long long a[n*m+1];
    bool t[n*m+1];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        t[i]=true;
    }
    for(int i=1;i<=n*m;i++)
    {
        long long max=a[1];
        for(int j=2;j<=n*m;j++)
        {
            if(max<a[j]&&t[j])
                max=a[j];
        }
        for(int j=1;j<=n*m;j++)
        {
            if(max==a[j])
            {
                t[j]=false;
                break;
            }
        }
        s++;
        if(t[1]==false)
            s--;
    }
    s++;
    if(s%n==0)
    {
        b=s/n;
        if(b%2==1)
            c=n;
        else
            c=1;
        cout<<b<<" "<<c<<endl;
        return 0;
    }
    else
        b=s/n+1;
    if(b%2==1)
        c=s%n;
    else
        c=n-(s%n)+1;
    cout<<b<<" "<<c<<endl;
    return 0;
}
