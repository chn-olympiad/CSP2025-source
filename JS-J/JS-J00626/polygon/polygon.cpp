#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
int a3()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(a[k]>a[i]+a[j])
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}
int a4()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                for(int q=k+1;q<=n;q++)
                {
                    if(a[q]>a[i]+a[j]+a[k])
                {
                    ans++;
                }
                }
            }
        }
    }
    return ans;
}

int a5()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                for(int q=k+1;q<=n;q++)
                {
                    for(int w=q+1;w<=n;w++)
                    {
                        if(a[w]>a[i]+a[j]+a[q]+a[k])
                        {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int a6()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                for(int q=k+1;q<=n;q++)
                {
                    for(int w=q+1;w<=n;w++)
                    {
                        for(int e=w+1;e<=n;e++)
                        {
                            if(a[e]>a[i]+a[j]+a[q]+a[k]+a[w])
                        {
                            ans++;
                        }
                        }
                    }
                }
            }
        }
    }
   return ans;
}
int a7()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                for(int q=k+1;q<=n;q++)
                {
                    for(int w=q+1;w<=n;w++)
                    {
                        for(int e=w+1;e<=n;e++)
                        {
                            for(int r=e+1;r<=n;r++)
                            {
                                if(a[r]>a[i]+a[j]+a[q]+a[k]+a[e]+a[w])
                                {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }return ans;
}
int a8()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                for(int q=k+1;q<=n;q++)
                {
                    for(int w=q+1;w<=n;w++)
                    {
                        for(int e=w+1;e<=n;e++)
                        {
                            for(int r=e+1;r<=n;r++)
                            {
                                for(int t=r+1;t<=n;t++)
                                {
                                    if(a[t]>a[i]+a[j]+a[q]+a[k]+a[e]+a[w]+a[r])
                                    {
                                    ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }return ans;
}
int a9()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                for(int q=k+1;q<=n;q++)
                {
                    for(int w=q+1;w<=n;w++)
                    {
                        for(int e=w+1;e<=n;e++)
                        {
                            for(int r=e+1;r<=n;r++)
                            {
                                for(int t=r+1;t<=n;t++)
                                {
                                    for(int y=t+1;y<=n;y++)
                                    {
                                        if(a[y]>a[i]+a[j]+a[q]+a[k]+a[e]+a[w]+a[r]+a[t])
                                {
                                    ans++;
                                }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }return ans;
}
int a10()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                for(int q=k+1;q<=n;q++)
                {
                    for(int w=q+1;w<=n;w++)
                    {
                        for(int e=w+1;e<=n;e++)
                        {
                            for(int r=e+1;r<=n;r++)
                            {
                                for(int t=r+1;t<=n;t++)
                                {
                                    for(int y=t+1;y<=n;y++)
                                    {
                                        for(int u=y+1;u<=n;u++)
                                        {
                                            if(a[u]>a[i]+a[j]+a[q]+a[k]+a[e]+a[w]+a[r]+a[t]+a[y])
                                {
                                    ans++;
                                    return ans;
                                }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }return ans;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3)
    {
        cout<<"0";
        return 0;
    }
    else if(n<4)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b+c||b>a+c||c>a+b)
        {
            cout<<"1";
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[1]==a[n]&&a[1]==1)
    {
        cout<<(n*n-5*n+6)/2;
        return 0;
    }
    if(n==3)
    {
        cout<<a3();
    }
    if(n==4)
    {
        cout<<a3()+a4();
    }
    if(n==5)
    {
        cout<<a3()+a4()+a5();
    }
    if(n==6)
    {
        cout<<a3()+a4()+a5()+a6();
    }
    if(n==7)
    {
         cout<<a3()+a4()+a5()+a6()+a7();
    }
    if(n==8)
    {
         cout<<a3()+a4()+a5()+a6()+a7()+a8();
    }
    if(n==9)
    {
         cout<<a3()+a4()+a5()+a6()+a7()+a8()+a9();
    }
    if(n==10)
    {
        cout<<a3()+a4()+a5()+a6()+a7()+a8()+a9()+a10();
    }
    return 0;
}
