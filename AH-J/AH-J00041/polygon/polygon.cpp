#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int z=1;
int b[5010];
int b1=0;
int zs=0;
int s=0;
int dp=0;
void geshu(int x)
{
    for(int i=z;i<=n;i++)
    {
        s++;
        b1+=i;
        b[s]=i;
        geshu(x-1);
    }
    if(x==0)
    {
        for(int i=1;i<=s;i++)
        {
            dp=max(dp,b[i]);
        }
        if(b1>2*dp)
        {
            zs++;
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=3;i<=n;i++)
    {
        b1=0;
        b[5010]={0};
        geshu(i);
    }
    cout<<zs;
    return 0;
}
