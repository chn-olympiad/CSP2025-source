#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==R)
        {
            int x;
            if(i%n==0)
            {
                x=i/n;
                cout<<i/n;
            }
            else
            {
                x=i/n+1;
                cout<<i/n+1;
            }
            cout<<" ";
            if(x%2==0)
            {
                cout<<n-i%n+1;
            }
            else
            {
                if(i%n==0)
                {
                    cout<<n;
                }
                else
                {
                    cout<<i%n;
                }
            }
        }
    }
    return 0;
}
