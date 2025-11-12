#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans,b[30],c[30],z,sum;
int ejz(int x)
{
    int m=0;
    for(int l=1;x!=0;l++)
    {
        b[l]=x%2;
        x/=2;
        m++;
    }
    return m;
}
int Ejz(int y)
{
    int m=0;
    for(int l=1;y!=0;l++)
    {
        c[l]=y%2;
        y/=2;
        m++;
    }
    return m;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
            ans++,a[i]=-10;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-10)
            continue;
        int t=ejz(a[i]);
        for(int l=i+1;l<=n;l++)
        {
            if(a[l]==-10)
            {
                l=n+1;
                continue;
            }
            int w=Ejz(a[l]);
            z=max(w,t);
            for(int j=1;j<=z;j++)
            {
                if(b[j]!=c[j])
                    b[j]=1;
                else
                    b[j]=0;
                c[j]=0;
            }
        }
        for(int l=1,j=1;l<=z;l++,j*=2)
        {
            sum+=b[l]*j;
        }
        if(sum==k)
            ans++;
        sum=0;
    }
    cout<<ans;
    return 0;
}
