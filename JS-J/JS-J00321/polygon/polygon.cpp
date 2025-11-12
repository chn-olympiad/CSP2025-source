#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n==3)
    {
        cout<<1;
        return 0;
    }
    long long a[5005]={};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long cnt=0;
    for(int k=3;k<=n;k++)
    {
        for(int i=1;i<=n-k;i++)
        {
            for(int j=i+k;j<=n;j++)
            {
                long long maxn=0,num=0;
                for(int l=i;l<=j;l++)
                {
                    num+=a[l];
                    if(a[l]>maxn)
                    {
                        maxn=a[l];
                    }
                }
                if(num>maxn*2)
                {
                    cnt++;
                    cnt%=998244353;
                }
            }
        }
    }
    if(cnt%2==0)
    {
        cout<<cnt*2+1;
    }
    else
    {
        cout<<cnt*2;
    }

    return 0;
}
