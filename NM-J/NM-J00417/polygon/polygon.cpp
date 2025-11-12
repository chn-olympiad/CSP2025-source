#include<bits/stdc++.h>
using namespace std;
int n,ju=0;
int a[10000],c[10000];
long long sum=1,res=0;
bool p[5001][5001]={};
bool fun(int l,int r)
{
    int maxn=0;
    long long k=0;
    for(int i=l;i<=r;i++)
    {
        k+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(k>maxn*2)    return true;
    else    return false;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=1)
        {
            ju=1;
        }
        c[i]=i;
    }
    if(n<=3)
    {
        if(n==3)
        {
            int maxn=0;
            maxn=max(max(a[1],a[2]),a[3]);
            if(a[1]+a[2]+a[3]>2*maxn)
            {
                cout<<1;
                return 0;
            }
            else
            {
                cout<<0;
                return 0;
            }
        }
        else
        {
            cout<<0;
            return 0;
        }

    }
    else if(ju==0)
    {
        sum=1;
        for(int i=3;i<=n;i++)
        {
            int l=n,r=1;
            sum=1;
            for(int j=1;j<=i;j++)
            {
                sum*=c[l];
                sum/=c[r];
                l--;
                r++;
                sum%=998244353;
            }
            res+=sum;
            res%=998244353;
        }
        cout<<res;
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[i][j]==1)
                {
                    continue;
                }
                else
                {
                    p[i][j]=1;
                    if(fun(i,j))
                    {
                        res++;
                        res%=998244353;
                    }
                }
            }
        }
        cout<<0;
        return 0;
    }
    return 0;
}
