#include<bits/stdc++.h>
using namespace std;
int a[5050],n,maxn;
long long sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    maxn=a[1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]>maxn)
        {
            maxn=a[i];
        }
    }
    if(n==3)
    {
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
        }
        if(sum>maxn*2)
        {
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
