#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N],maxn=-N,vis[N];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+1+n);
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>maxn*2)
            cout<<1;
        else cout<<0;
        return 0;
    }
    if(n==4)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    for(int l=k+1;l<=n;l++)
                    {
                        if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
                            num++;
                    }
                    if(a[i]+a[j]+a[k]>a[k]*2)
                        num++;
                }
            }
        }
        cout<<num;
    }
    if(n==5)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {

                    for(int l=k+1;l<=n;l++)
                    {

                        for(int q=l+1;q<=n;q++)
                        {
                            if(a[i]+a[j]+a[k]+a[l]+a[q]>a[q]*2)
                                num++;
                        }
                        if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
                            num++;
                    }
                    if(a[i]+a[j]+a[k]>a[k]*2)
                        num++;
                }
            }
        }
        cout<<num;
    }
    if(n==6)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {

                    for(int l=k+1;l<=n;l++)
                    {

                        for(int q=l+1;q<=n;q++)
                        {
                            for(int w=q+1;w<=n;w++)
                            {
                                if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]>a[w]*2)
                                    num++;
                            }
                            if(a[i]+a[j]+a[k]+a[l]+a[q]>a[q]*2)
                                num++;
                        }
                        if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
                            num++;
                    }
                    if(a[i]+a[j]+a[k]>a[k]*2)
                        num++;
                }
            }
        }
        cout<<num;
    }
    if(n==7)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {

                    for(int l=k+1;l<=n;l++)
                    {

                        for(int q=l+1;q<=n;q++)
                        {
                            for(int w=q+1;w<=n;w++)
                            {
                                for(int e=w+1;e<=n;e++)
                                {
                                    if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]>a[e]*2)
                                        num++;
                                }
                                if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]>a[w]*2)
                                    num++;
                            }
                            if(a[i]+a[j]+a[k]+a[l]+a[q]>a[q]*2)
                                num++;
                        }
                        if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
                            num++;
                    }
                    if(a[i]+a[j]+a[k]>a[k]*2)
                        num++;
                }
            }
        }
        cout<<num;
    }
    if(n==8)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {

                    for(int l=k+1;l<=n;l++)
                    {

                        for(int q=l+1;q<=n;q++)
                        {
                            for(int w=q+1;w<=n;w++)
                            {
                                for(int e=w+1;e<=n;e++)
                                {
                                    for(int r=e+1;r<=n;r++)
                                    {
                                        if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]>a[r]*2)
                                            num++;
                                    }
                                    if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]>a[e]*2)
                                        num++;
                                }
                                if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]>a[w]*2)
                                    num++;
                            }
                            if(a[i]+a[j]+a[k]+a[l]+a[q]>a[q]*2)
                                num++;
                        }
                        if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
                            num++;
                    }
                    if(a[i]+a[j]+a[k]>a[k]*2)
                        num++;
                }
            }
        }
        cout<<num;
    }
    if(n==9)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {

                    for(int l=k+1;l<=n;l++)
                    {

                        for(int q=l+1;q<=n;q++)
                        {
                            for(int w=q+1;w<=n;w++)
                            {
                                for(int e=w+1;e<=n;e++)
                                {
                                    for(int r=e+1;r<=n;r++)
                                    {
                                        for(int t=r+1;t<=n;t++)
                                        {
                                            if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]>a[t]*2)
                                                num++;
                                        }
                                        if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]>a[r]*2)
                                            num++;
                                    }
                                    if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]>a[e]*2)
                                        num++;
                                }
                                if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]>a[w]*2)
                                    num++;
                            }
                            if(a[i]+a[j]+a[k]+a[l]+a[q]>a[q]*2)
                                num++;
                        }
                        if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
                            num++;
                    }
                    if(a[i]+a[j]+a[k]>a[k]*2)
                        num++;
                }
            }
        }
        cout<<num;
    }
    if(n==10)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {

                    for(int l=k+1;l<=n;l++)
                    {

                        for(int q=l+1;q<=n;q++)
                        {
                            for(int w=q+1;w<=n;w++)
                            {
                                for(int e=w+1;e<=n;e++)
                                {
                                    for(int r=e+1;r<=n;r++)
                                    {
                                        for(int t=r+1;t<=n;t++)
                                        {
                                            for(int y=1;y<=n;y++)
                                            {
                                                if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]>a[t]*2)
                                                    num++;
                                            }
                                            if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]+a[t]>a[t]*2)
                                                num++;
                                        }
                                        if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]+a[r]>a[r]*2)
                                            num++;
                                    }
                                    if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]+a[e]>a[e]*2)
                                        num++;
                                }
                                if(a[i]+a[j]+a[k]+a[l]+a[q]+a[w]>a[w]*2)
                                    num++;
                            }
                            if(a[i]+a[j]+a[k]+a[l]+a[q]>a[q]*2)
                                num++;
                        }
                        if(a[i]+a[j]+a[k]+a[l]>a[l]*2)
                            num++;
                    }
                    if(a[i]+a[j]+a[k]>a[k]*2)
                        num++;
                }
            }
        }
        cout<<num;
    }
    return 0;
}
