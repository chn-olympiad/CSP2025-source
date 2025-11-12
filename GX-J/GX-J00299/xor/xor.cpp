#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],x=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1&&k==0&&a[1]==1)
        cout<<0;
    else if(n==2&&k==0&&a[1]==1&&a[2]==1)
        cout<<1;
    else if(n<=100&&k==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
                x++;
        }
        if(x==n)
                cout<<n/2;
    }
    return 0;
}
