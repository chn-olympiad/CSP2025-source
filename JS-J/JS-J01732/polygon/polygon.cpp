#include<bits/stdc++.h>
using namespace std;

int n;
int a[5001];
int ans;
int sum;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+n+1);
    if(n==3)
    {
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
        }
        if(sum>a[n]*2)
            ans+=1;
    }
    else
    {
        ans=pow(2,(n-3)*2);
    }
    cout<<ans%998244353;
    return 0;
}
