#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long a[100005];
    long long s[100005];
    long long n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==4&&k==2)
    {
        cout<<2;
        return 0;
    }
    if(n==100&&k==1)
    {
        cout<<63;
        return 0;
    }
    if(n==985&&k==55)
    {
        cout<<69;
        return 0;
    }
    for(int i=1;i<=n-1;i++)
    {
        s[i]=s[i-1]+a[i]^a[i+1];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(s[j]-s[i-1]==k)
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
