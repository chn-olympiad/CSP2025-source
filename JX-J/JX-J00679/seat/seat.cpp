#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x=1;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        int s=a[1];
        if(a[i]>s)
        {
            x++;
        }
    }
    while(n--)
    {
        if(n*m<x)
        {
            cout<<n+1<<" ";
            if(n%2==0)
            {
                cout<<x-n*m;
            }
            else
            {
                int b=x-n*m;
                if(m%2==0)
                {
                    m++;
                    m=m/2;
                }
                else
                {
                    if(m%2+1==b)
                    {
                        cout<<b;
                        return 0;
                    }
                    m=m/2;
                }
                if(b>m)
                {
                    cout<<b-(max(b,m)-min(b,m))*2;
                }
                else if(m>b)
                {
                    cout<<b+(max(b,m)-min(b,m))*2;
                }
                else if(m==b)
                {
                    cout<<b+1;
                }
            }
            break;
        }
    }
    return 0;
}

