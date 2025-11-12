#include<bits/stdc++.h>
using namespace std;
int a[1111];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int t=a[0];
    sort(a,a+n*m);
    reverse(a,a+n*m);
    for(int i=0;i<n*m;i++)
    {
        if(t==a[i])
        {
            t=i;
            break;
        }
    }
    if((t/n)%2==0)
    {
        cout<<(t/n)+1<<" ";
        cout<<(t%n)+1;
    }
    else
    {
        cout<<(t/n)+1<<" ";
        cout<<n-(t%n);
    }
    return 0;
}