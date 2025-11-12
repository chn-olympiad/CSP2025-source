#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans;
bool flagA=1,flagB=1;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            flagA=0;
            if(a[i]!=0)
                flagB=0;
        }
    }
    if(flagA==1)
    {
        ans=n/2;
        cout<<ans;
        return 0;
    }
    if(flagB==1)
    {
        if(k==0)
        {
            for(long long i=0;i<n;i++)
            {
                if(a[i]==0)
                    ans++;
                if(a[i]==1 and i+1<n and a[i+1]==1)
                    ans++,i+=1;
            }
        }
        if(k==1)
        {
            for(long long i=0;i<n;i++)
            {
                if(a[i]==1)
                    ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
