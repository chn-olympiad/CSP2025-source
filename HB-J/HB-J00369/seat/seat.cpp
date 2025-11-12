#include<bits/stdc++.h>

using namespace std;

int n,m,a[105],a1,flag,f;

int  main(void)
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    a1=a[1];

    sort(a+1,a+t+1);

    for(int i=1;i<=t;i++){
        if(a[i]==a1)
        {
            flag=t-i+1;
        }
    }

    for(int i=0;i<=9;i++){
        if(flag<=(i+1)*n&&flag>i*n)
        {
            f=i+1;
        }
    }

    cout<<f<<" ";
    if(f%2==0)
    {
        cout<<m-(flag-f)+1;
    }else
    {
        cout<<flag-m*(f-1);
    }

    return 0;
}
