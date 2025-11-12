#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
long long z=0;
void s(int n,int l,int v)
{
    if(n==0)
    {
        long long x=0;
        for(int j=1;j<v;j++)
        {
            x+=b[j];
        }
        if(b[v]<x) z=(z+1)%998244353;
        return;
    }
    for(int i=n;i<l;i++)
    {
        b[n]=a[i];
        n--;
        s(n,i,v);
        n++;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
    {
        s(i,n+1,i);
    }
    cout<<z<<'\n';
    return 0;
}
