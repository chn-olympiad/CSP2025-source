#include<bits/stdc++.h>
using namespace std;
int n,x[5005],s;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }sort(x+1,x+n+1);
    if(n==3)
    {
        if(x[1]+x[2]>x[3])cout<<1;
        else cout<<0;
        return 0;
    }
    else if(x[n]==x[1])
    {
        for(int i=1;i<=n-2;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                s+=(n-j);
            }
        }cout<<s;return 0;
    }
    else if(n<=10)

    return 0;
}
