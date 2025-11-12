#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
bool cmp (int x,int y)
{
    return x>y;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    long long m=n-2,sum;
    for(int i=1;i<=m;i++)
    {
        sum+=i*i;
    }
    cout <<sum%998244353;
    return 0;
}
