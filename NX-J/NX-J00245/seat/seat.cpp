#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1003],l=1,h=1,cr;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++)
    {
        cin>>a[i];
    }
    cr=a[1];
    for(int i=1; i<=n*m; i++)
    {
        for(int z=1; z<n*m; z++)
        {
            if(a[z]<a[z+1])
            {
                swap(a[z],a[z+1]);
            }
        }
    }
    for(int i=1; i<=n*m; i++)
    {
        if(a[i]==cr)
        {
            cout<<l<<" "<<h;
            return 0;
        }
        if(i%n==0)
        {
            l++;
        }
        if(i%n%2==1&&i!=1)
        {
            h--;
        }
        else if(i%n%2!=0)
        {
            h++;
        }
    }
    return 0;
}
