#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            ans++;
        }
    }
    int tmp=0;
    for(int i=1;i<=n;i++)
    {
        tmp=0;
        if(a[i]==k)
        {
            continue;
        }
        for(int j=i;j<=n;j++)
        {
            if(a[j]==k)
            {
                break;
            }
            tmp^=a[j];
            if(tmp==k)
            {
                ans++;
                i=j;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
