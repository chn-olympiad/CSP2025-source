#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500000];
int pd(int h,int t)
{
    int ra=a[h];
    for (int i=h;i<=t;i++)
    {
        ra=ra^a[i];
    }
    return ra==k;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long sum=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            sum+=pd(i,j);
        }
    }
    cout<<sum;
    return 0;
}
