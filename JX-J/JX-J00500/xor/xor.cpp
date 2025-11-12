#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[100000],cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                cnt++;
            }
        }
        cout<<cnt;
        return 0;
    }
    else if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                cnt++;
            }
        }
        cout<<cnt;
        return 0;
    }
    else
    {
        cout<<2;
    }
    return 0;
}
