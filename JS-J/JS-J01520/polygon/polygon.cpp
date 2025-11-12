#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
long long num;
int checknum(int x)
{
    int c=0,maxx=0;
    for(int j=1;j<=x;j++)
    {
        c+=b[j];
        maxx=max(maxx,b[j]);
    }
    if(c>maxx*2)
    {
        return 1;
    }
    return 0;
}
int searchnum(int id,int sum,int z)
{
    if(id>n+1)
    {
        return 0;
    }
    if(sum>=3&&z==1)
    {
        if(checknum(sum))
        {
            num++;
            num=num%998244353;
        }
    }
    searchnum(id+1,sum,0);
    b[sum+1]=a[id];
    searchnum(id+1,sum+1,1);
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
    searchnum(1,0,0);
    cout<<num;
    return 0;
}
