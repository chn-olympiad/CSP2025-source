#include<bits/stdc++.h>
using namespace  std;
long long n;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>i;
    }
    for(int i=1;i<=n;i++)
    {
        int a=i+i-1+i-2;
        int b=max(i,i-1,i-2)*2;
        if(a>b)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
