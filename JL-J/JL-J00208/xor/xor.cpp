#include <bits/stdc++.h>
using namespace std;
const int N=500007;
int n,k,a[N],ans=1,maxv=-1;
int main()
{
    freopen("xor.in","w",stdin);
    freopen("xor.out","r",stdout);
    cin>>n>>k;
    if(k==0)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=i+k;j++)
        {
            ans&=a[i]&a[i-1];
        }
        maxv=max(maxv,ans);
        ans=1;
    }
    cout<<maxv;
    return 0;
}
