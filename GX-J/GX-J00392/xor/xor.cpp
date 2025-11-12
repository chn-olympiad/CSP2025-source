#include<bits/stdc++.h>
using namespace std;
int main()
{
    feopen("xor.in","r",stdin);
    feopen("xor.out","w",stdout);
    long long n,k;
    int num=0;
    int a[500001];
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            num++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]-a[i]==k)
            {
                num++;
            }
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]-a[j]==k)
            {
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}
