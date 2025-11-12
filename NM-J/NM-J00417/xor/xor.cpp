#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500100],ju=0;
int p[1010][1010]={};
long long sum=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            ju=1;
        }
    }
    if(ju==0)
    {
        cout<<n/2;
        return 0;
    }
    else
    {
        for(int i=0;i<n-1;i++)
        {
            if(p[i][i+1]==1)
            {
                continue;
            }
            else
            {
                p[i][i+1]=1;
                if(a[i]^a[i+1]==k)
                {

                    sum++;
                }
            }
        }
        cout<<sum;
    }
    return 0;
}
