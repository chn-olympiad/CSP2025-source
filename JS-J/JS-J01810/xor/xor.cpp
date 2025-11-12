#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,x,sum,maxsum;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        sum=0;
        x=a[i];
        for(int j=i+1;j<=n&&j!=i;j++)
        {
            if(x==k&&maxsum<sum)
            {
                maxsum=sum;
            }
            x=x^a[j];
            sum++;
            if(x==k&&maxsum<sum)
            {
                maxsum=sum;
            }
        }
    }
    cout<<maxsum;
    return 0;
}
