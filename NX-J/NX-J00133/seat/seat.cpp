#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        b=a[1];
    }
    int x=n*m;
    for(int i=1;i<=x;i++)
    {
        for(int j=i;j<=x;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    int c;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==b)
        {
            if(i%m!=0)
            {
                c=i/m+1;
            }
            else
            {
                c=i/m;
            }
            if(c%2==1)
            {
                cout<<c<<" ";
                if(i%n==0)
                {
                    cout<<n;
                }
                else
                {
                    cout<<i%n;
                }
                return 0;
            }
            else
            {
                cout<<c<<" "<<n-i%n+1;
                return 0;
            }
        }
    }
}
