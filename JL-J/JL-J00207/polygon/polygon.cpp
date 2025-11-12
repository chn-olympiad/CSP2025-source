#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,maxn,aaa=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int ans=0;
            for(int k=i;k<=j;k++)
                  ans=ans+a[k];
            if(ans>maxn*2)
                    aaa++;
        }
    }
    cout<<aaa;
    return 0;
}
