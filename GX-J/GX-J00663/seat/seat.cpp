#include<bits/stdc++.h>
using namespace std;

int main ()
{
    freopen("seat1.in","r",stdin);
    freopen("seat1.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int a[n*m],b;

    for(int i=0;i<n*m;i++)
        cin>>a[i];
    b=a[0];

    sort(a,a+n*m);

    for(int i=n*m-1;i>=0;i--)
    {
        if(a[i]==b)
            b=n*m-i;
    }


    if(b%n==0)
    {
        if(b%m==0)
            cout<<b/n<<" "<<m;
        else
            cout<<b/n<<" "<<b%m;
    }
    else
    {
        if(b%m==0)
            cout<<b/n+1<<" "<<m;
        else
            cout<<b/n+1<<" "<<b%m;
    }
    return 0;
}
