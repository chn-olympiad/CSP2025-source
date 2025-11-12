#include<bits/stdc++.h>
using namespace std;
int n,maxn;
struct node
{
    int x,y[40],l=1;
}a[500001],kk,s[500001][500001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>kk.x;
    int t=kk.x;
    while(t)
    {
        kk.y[kk.l]=t%2;
        t/2;
        kk.l++;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x;
        int t=a[i].x;
        while(t)
        {
            a[i].y[a[i].l]=t%2;
            t/2;
            a[i].l++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=a[i].l;k++)
        {
            s[i][i].y[k]=a[i].y[k];
            s[i][i].l=a[i].l;
        }
        for(int j=i+1;j<=n;j++)
        {
            s[i][j].l=max(s[i][j-1].l,a[j].l);
            for(int k=1;k<=s[i][j].l;k++)
            {
                s[i][j].y[k]=(s[i][j-1].y[k]+a[j].y[k])%2;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(s[i][j].l==kk.l)
            {
                int f=1;
                for(int k=1;k<=kk.l;k++)
                {
                    if(s[i][j].y[k]!=kk.y[k])
                    {
                        f=0;
                        break;
                    }
                }
                if(f)
                {
                    s[i][j].x=1;
                }
            }
        }
    }
    while(true)
    {
        int f=1,ans=0,p=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(s[i][j].x==1)
                {
                    f=0;
                }
            }
        }
        if(f)
        {
            cout<<maxn;
            return 0;
        }
        f=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(s[i][j].x==1)
                {
                    if(f)
                    {
                        s[i][j].x=0;
                        f=0;
                    }
                    if(i>p)
                    {
                        ans++;
                        p=j;
                    }
                }
            }
        }
        maxn=max(maxn,ans);
    }
    return 0;
}
