#include<bits/stdc++.h>
using namespace std;
int nn[5000];
int main()
{
    int z=2,n,r=0;
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>nn[i];
    }
    for(z=2;z<=n;z++)
    {
        r=0;
        while(r<=n-z)
        {
            int j=0,maxj=-1;
            for(int k=0;k<=z;++k)
            {
                j+=nn[r+k];
                if(nn[r+k]>maxj)
                maxj=nn[r+k];
            }
            if(j>maxj*2)
                ans++;
        }
    }
    cout<<ans%998244353;
    return 0;
}
