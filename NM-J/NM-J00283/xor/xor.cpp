#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500005],ans;

int j2(int x)
{
    if(x==1||x==0)
    {
        return x;
    }
    return j2(x/2)*10+x%2;
}

int xo(int a,int b)
{
    int ans=0,num=1;
    while(a!=0||b!=0)
    {
        int x=a%10;
        int y=b%10;
        if(x!=y)
        {
            ans+=num;
        }
        num*=10;
        a/=10;
        b/=10;
    }
    return ans;
}

int j10(int x)
{
    int ans=0;
    int num=2;
    int b=x%10;
    x/=10;
    while(x!=0)
    {
        ans+=(x%10)*num;
        x/=10;
        num*=2;
    }
    return ans+b;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            int sum=0;
            for(int i=l;i<=r;i++)
            {
                sum=j10(xo(j2(sum),j2(a[i])));
            }
            if(sum==k)
            {
                ans++;
                l=r;
            }
        }
    }
    cout<<ans;
    return 0;
}
