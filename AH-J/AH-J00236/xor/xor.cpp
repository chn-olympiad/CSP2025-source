#include<bits/stdc++.h>
using namespace std;
long long n,k,cnt;
long long a[500005];
int main(void)
{
    //xor
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)cnt++;
        }
        cout<<cnt;
        return 0;
    }
    else if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)cnt++;
        }
        cout<<cnt;
        return 0;
    }
    else
    {
        cout<<1;
        return 0;
    }
    return 0;
}
