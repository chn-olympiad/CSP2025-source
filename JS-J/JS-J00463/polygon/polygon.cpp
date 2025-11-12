//40pts
#include<bits/stdc++.h>
using namespace std;
int n;
int a[5003];
long long sum;
void pinhaoxing(long long num,long long loong,long long now,long long mmax)//shu'liang | zong'chang'du | dang'qian'wei'zhi.
{
    if(a[now]>mmax)
        mmax=a[now];
    if(num>=3)
    {
        if(loong>mmax*2)
        {
            sum++;
            sum%=998244353;
        }
        if(num>n)
        {
            return;
        }
    }
    for(int i=now+1;i<=n;i++)
    {
        pinhaoxing(num+1,loong+a[i],i,mmax);
    }
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
    for(int i=1;i<=n-2;i++)
    {
        pinhaoxing(1,a[i],i,0);
    }
    cout<<sum<<"\n";
    return 0;
}