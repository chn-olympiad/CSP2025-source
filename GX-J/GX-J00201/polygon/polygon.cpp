#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[5005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin<<a[i];
    }
    if(n==3)
    {
        int t=0;
        t=max(a[1],t);
        t=max(a[2],t);
        t=max(a[3],t);
        if(t*2>a[1]+a[2]+a[3])
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    int y=0;
    for(int i=3;i<=n;i++)
    {
        for(int j=i;i<=n;j++)
        {
            y++;
        }
    }
    cout<<y;
    return 0;
}
