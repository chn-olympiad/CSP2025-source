#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],sum[200005],ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=a[i];
    }
    sort(sum+1,sum+n+1);
    if(sum[1]==sum[n])
    {
        cout<<n/2;
        return 0;
    }
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                ans++;
            }
        }
    }
    else
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                num++;
                if(num==2)
                {
                    num=0;
                    ans++;
                }
            }
            else
            {
                num=0;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
