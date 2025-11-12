#include<bits/stdc++.h>
using namespace std;
int a[100001];
int n,k,w,b,c;
int erjinzhi(int b)
{
    int cnt=b%2;
    for(int i=b/2;i!=0;i/=2)
    {
       cnt+=(i%2)*10;
    }
    return cnt;
}
int quanzhi(int x,int y)
{
    int s=0;
    if(x==y)
    {
        return a[x];
    }

    b=erjinzhi(a[x]);
    c=erjinzhi(a[x+1]);
    for(int i=max(b,c);i>=1;i/=10)
    {
        if(b%10==c%10)
        {
            s=s*10;

        }
        else
        {
            s=s*10+1;
        }
        b/=10;
        c/=10;
    }
    for(int i=x+2;i<y;i++)
    {
        c=erjinzhi(a[i]);
        int d,e;
        for(int z=max(s,c);z>=1;z/=10)
        {
            if(z==max(s,c))
            {
                d=s;
                e=c;
            }
            if(d%10==e%10)
            {
                s=s*10;
            }
            else
            {
                s=s*10+1;
            }
            d/=10;
            e/=10;
        }
    }
    int f=0;
    int i=1;
    while(s!=0)
    {

        if(s%10==1)
            f+=i;
        s/=10;
        i*=2;
    }
        return f;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int maxx=0,flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int l=1;l<=n;l=flag+1)
    {
        for(int r=l;r<=n;r++)
        {
            if(quanzhi(l,r)==k)
            {
                maxx++;
                flag=r;
                break;
            }
        }
    }
    cout<<maxx;
    return 0;
}
