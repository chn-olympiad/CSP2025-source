#include<bits/stdc++.h>
using namespace std;
int n,a[5000];
int pd(int h,int t)
{
    int summ=0,maxn=0;
    for (int i=h;i<=t;i++)
    {
        summ+=a[i];
        maxn=max(maxn,a[i]);
    }
    return summ>maxn*2;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i+2;j<n;j++)
        {
            sum+=pd(i,j);
        }
    }
    cout<<sum;
    return 0;
}
