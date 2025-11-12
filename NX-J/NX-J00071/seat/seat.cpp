#include<bits/stdc++.h>
using namespace std;
long long a[105],n,m,l=0,i,j;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    long long x=a[1];
    sort(a,a+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==x)
        {
            l=n*m-i+1;
        }
    }
    if(l%n!=0)
    {
        i=l/n+1;
    }
    else if(l%n==0)
    {
        i=l/n;
    }
    if(l%n==0 && (l/n-1)%2==0)
    {
        j=n;
    }
    else if(l%n==0 && (l/n-1)%2!=0)
    {
        j=1;
    }
    else if(l%n!=0 && (l/n)%2==0)
    {
        j=l%n;
    }
     else if(l%n!=0 && (l/n)%2!=0)
    {
        j=n-(l%n-1);
    }
    cout<<i<<" "<<j;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
