#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    int a[n+1];
    long long ans=0;
    long long e=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int l=1;l<=n;l++)
    {
        for(int r=1;r<=n;r++)
        {
            if(l>e)
            {
                long long sum=0;
                for(int i=l;i<=r;i++)
                {
                    sum=sum^a[i];
                }
                if(sum==k)
                {
                    ans++;
                    e=r;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
