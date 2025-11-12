#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,maxn=-1,b[500005],ans[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int sum=a[i];
        for(int j=i-1;j>=0;j--)
        {
            if(sum==k)
            {
                b[i]=j+1;
            }
            sum^=a[j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            ans[i]=ans[i-1];
        }
        else
        {
            ans[i]=max(ans[i-1],ans[b[i]-1]+1);
        }
    }
    printf("%d",ans[n]);
    return 0;
}
