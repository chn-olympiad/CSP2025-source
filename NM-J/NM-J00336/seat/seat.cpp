#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int g=n*m;
    vector<int> a(n*m+1);
    for(int i=1; i<g; i++)
    {
        cin>>a[i];
    }
    int p=a[1];
    int c;
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            if(a[j]<a[i+1])
            {
                c=a[j];
                a[j]=a[i+1];
                a[i+1]=c;
            }
        }
    }
    int t;
    for(int i=1; i<n+1; i++)
    {
        if(p==a[i])
        {
            t=i;
        }
    }
    int e,r;

    if(t<=n)
    {
        e=n-1;
        r=t;
    }
    else if(t>n)
    {
        e=t;
        r=t;
    }

    cout<<e<<" "<<r;
    return 0;
}
