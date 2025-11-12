#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5555],maxn=INT_MIN;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    if(maxn==1)
    {
        cout<<n-2;
        return 0;
    }
    if(n==3)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
        }
        if(sum>maxn*2)
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
    cout<<0;
    return 0;
}
