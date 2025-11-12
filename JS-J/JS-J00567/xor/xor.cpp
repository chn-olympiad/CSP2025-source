#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
    {
       for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                ans++;
            }
            else
            {
                if(a[i+1]==a[i])
                {
                    ans++;
                    i++;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
