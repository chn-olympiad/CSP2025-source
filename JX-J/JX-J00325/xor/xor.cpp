#include<bits/stdc++.h>
using namespace std;
long long n,a[200098],k,a0,a1,cnt;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) a1++;
        else if(a[i]==0) a0++;
    }
    if(a1==n && k==0)
    {
        cout<<a1/2;
        return 0;
    }
    else if(k==1)
    {
       cout<<a1;
       return 0;
    }
    else if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[i+1])
            {
                cnt++;
                i++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
