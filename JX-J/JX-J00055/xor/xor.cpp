#include<bits/stdc++.h>
using namespace std;

int er(int a)
{
    int s=0,b=0;
    if(a<2)
    {
        return a%2;
    }
    while(a>1)
    {
        s+=a%2*pow(10,b);
        a/=2;
        b++;
    }
    return s+a*pow(10,b);
}
int yh(int a,int b)
{
    int a1[1000]={0},b1[1000]={0},i=0;
    while(a>0||b>0)
    {
        if(a%10!=b%10)
        {
            i++;
        }
        a/=10;
        b/=10;
    }
    return i;
}
int n,k,a[500010],dp,dx;
bool b[500010]={1};
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
        int tem;
        dx=a[i];
        for(int j=i+1;j<=n;j++)
        {
            if(b[i])
                if(dx<k)
                {
                    dx+=yh(er(a[j]),dx);
                    tem=j;
                }

        }
        if(dx==k)
        {
            dp++;
            for(int l=i;l<=tem;l++)
            {
                b[i]=0;
            }
        }
    }
    cout<<dp;
    return 0;
}
