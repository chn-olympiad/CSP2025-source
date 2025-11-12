#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0,num=0;
    cin>>n>>k;
    int a[n+2];
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<k;i++)
    {
        ans++;
    }
    for (int i=k+1;i<=n;i++)
    {
        num++;
    }
    int maxxn=max(num,ans);
    cout<<maxxn;
    return 0;
}
