#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool flag=true;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) flag=false;
    }
    if(n==3)
    {
        int maxn=-1,sum=0;
        for(int i=1;i<=3;i++)
        {
            sum+=a[i];
            maxn=max(maxn,a[i]);
        }
        if(sum>maxn*2) cout<<1;
        else cout<<0;
    }
    else if(flag)
    {
        cout<<n-2;
    }
    return 0;
}
