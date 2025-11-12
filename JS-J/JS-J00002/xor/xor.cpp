#include<bits/stdc++.h>
using namespace std;
int a[10005],n,k;
long long ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int t=0;
    long long cnt;
    for(int i=1;i<=n;i++)
    {
        if(i<=t) continue;
        cnt=a[i];
        if(cnt==k)
        {
            t=i;
            ans++;
            continue;
        }
        for(int j=i+1;j<=n;j++)
        {
            cnt^=a[j];
            if(cnt==k)
            {
                t=j;
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
