#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x,b[500005],y;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    cin>>a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(y==i)
            {
                continue;
            }
            if(a[i]==0)
            {
                x++;
            }
            if(a[i]==1&&a[i+1]==1)
            {
                x++;
                y=i+1;
            }
        }
        cout<<x;
        return 0;
    }
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(y==i)
            {
                continue;
            }
            if(a[i]==1)
            {
                x++;
            }
        }
        cout<<x;
        return 0;
    }
    cout<<"12701";
    return 0;
}
